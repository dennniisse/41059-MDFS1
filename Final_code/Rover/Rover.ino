/* DIGITAL PINS
 *  1
 *  2 
 *  3 
 *  4
 *  5 
 *  6
 *  7 
 *  8 
 *  9 
 *  10 
 *  11 
 *  12
 *  13
*/

/* ANALOGUE PINS
 *  A0: LDR1
 *  A1: LDR2int current_time = 0;
  int previous_time = millis();
  
  if(secure_payload_bool == true)
  {
    while(current_time - previous_time < motor_delay)
    {
      current_time = millis();
      digitalWrite(inA, HIGH);
      digitalWrite(inB, LOW);       
    }
  }

  myDelay(1500);

  digitalWrite(inA, LOW);
  digitalWrite(inB, LOW); 
  delay(500);   
*/

#include <Servo.h>
//#include <PID_v1.h> //not currently used

/////////////////////////////////////////////////////////////////////////
// TIME VARIABLES TO CHANGE
int lift_wait = 5000; //how long to wait before we lift
int zipline_wait = 17000; //how long to wait before releasing gripper
/////////////////////////////////////////////////////////////////////////

//BOOLEAN values (SET ALL TO FALSE UNLESS TESTING) 
bool end_code = true;
bool wheel_bool = true; //true means rover motor to move
bool ldr1_bool = false; //true means ldr1 has been detected 
bool ldr2_bool = false; //true means ldr2 has been detected 
bool secure_payload_bool = false; //true means gripper will close
bool lift_bool = false;

Servo servo;
const int horizontalServo = 8;
const int verticalServoPin = 9;

//variable for motor speed 
double m_speed;
/////////////////////////////////////////////////////////////////////////
// MOTOR SPEED TO CHANGE
int start_v = 30;
int slow_v = 10;
/////////////////////////////////////////////////////////////////////////

//drive_control
//LHS Motor 1
const int E1 = 3;
const int M1 = 4;

//RHS Motor 2
const int E2 = 11;
const int M2 = 12;

//servo DC Motor
const int inA = A2;
const int inB = A3;
int motor_delay = 1000;

//LDR Sensors
const int LDR1 = A0;
const int LDR2 = A1;
//LDR values storage 
int LDR1_val;
int LDR2_val;
//threshold values to be tested
int LDR_threshold = 900;

//functions
void myDelay(unsigned long to_delay);
void setMotor(void);
void runMotor(unsigned int speed);
void setEncoder(void);
void setUpGripper(void);
void detectPayLoad(void);


//variable
bool servo_flag = false;
bool slow_detection = false;
bool stop_detection = false;

void setup() {

  setMotor();
  servo.attach(9);
  Serial.begin(9600); 

  //ensure gripper is at 0 degrees prior to starting 
  setUpGripper();

}

void loop() {

  Serial.println("Code begin");
  
  ///////////////////////////////////////////////////////////////WINCH AND ROVER TO GROUND////////////////////////////////////////////////////////////////////
  

  ///////////////////////////////////////////////////////////////DRIVE TO PAYLOAD////////////////////////////////////////////////////////////////////

  //activate the motor wheels 
  if(wheel_bool == true)//friction of ball bearings needs consideration, as it will affect the speed
  {
    runMotor(start_v);
    //Serial.println("Wheel move");
  }
  
  ///////////////////////////////////////////////////////////////PICK UP PAYLOAD////////////////////////////////////////////////////////////////////
  //constantly flag LDR sensor for any changes
  //Serial.println("Read LDR1");
  while(ldr1_bool == false)
  {    
    //if there is a change with first LDR sensor 
    ldr1_bool = detectPayLoad(1);
    if(ldr1_bool == true) //safety function to ensure we exit the while loop if boolean value changes 
    {
      runMotor(slow_v);
      break;
    }
    myDelay(100);       
  }

  runMotor(slow_v); //slow down
    
  //Serial.println("LDR2");
  while(ldr2_bool == false)
  {
    ldr2_bool = detectPayLoad(2);
    //second LDR sensor change
    if(ldr2_bool == true){
      //runMotor(0);
      lift_bool = true;
      break;
    }   

     myDelay(100);
  }
  
  myDelay(2500);  //delay that allows the motor to move in a bit more before it stops, this is hardcoded, trial and error
  //Serial.println("Wheel stopped");
 
  runMotor(0); //stop motor wheels

  myDelay(1000);

  lift_bool = true;
  
  //activate DC(servo)motor to grip the payload => measure time to rotate DC motor 
  //securePayLoad(false);
  digitalWrite(inA, HIGH);
  digitalWrite(inB, LOW);

  //Serial.println("LIFTING TIME");
  myDelay(lift_wait);
  //rotate the servo motor
  if(lift_bool == true){
    servoLift();
  }

  myDelay(zipline_wait);
  
  //securePayLoad(true);
   digitalWrite(inA, LOW);
   digitalWrite(inB, HIGH);
  //time delay to give rover time to secure paylaod

  ///////////////////////////////////////////////////////////////RETURN TO ZIPLINE ROLLER////////////////////////////////////////////////////////////////////
  //using the flag from LDR sensor, have zipline roller bring rover back

  //time delay or use encoder

  ///////////////////////////////////////////////////////////////MOVE TO DEPOSIT ZONE////////////////////////////////////////////////////////////////////
  //active the DC motors on zipline roller

  //time delay

  ///////////////////////////////////////////////////////////////DELIVER PAYLOAD////////////////////////////////////////////////////////////////////
  //activate DC motor winch to drop rover down (may not have to do test)

  //activate DC(servo) gripper, reverse direction to open the gripper 

  //time delay to let wheel drop

  ///////////////////////////////////////////////////////////////RETURN TO START ZONE////////////////////////////////////////////////////////////////////
  //active the DC motors on zipline roller 

  //THE END//
  myDelay(5000);
  exit(0);    
}

void myDelay(int timeToWait){
  int currentTime = 0;
  int previousTime = millis();

  do{
    currentTime = millis(); 
    //do nothing
  }while(currentTime - previousTime <= timeToWait);

  currentTime = 0;
  previousTime = 0;
  
}
