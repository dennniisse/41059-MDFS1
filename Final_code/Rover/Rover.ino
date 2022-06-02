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
 *  A1: LDR2
*/

#include <Servo.h>
//#include <PID_v1.h> //not currently used

Servo servo_gripper;
const int horizontalServo = 8;
const int verticalServoPin = 9;

//variable for motor speed 
double m_speed;
//drive_control
//LHS Motor 1
const int E1 = 3;
const int M1 = 4;

//RHS Motor 2
const int E2 = 11;
const int M2 = 12;

//LDR Sensors
const int LDR1 = A0;
const int LDR2 = A1;

int LDR1_val;
int LDR2_val;


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
  servo_gripper.attach(verticalServoPin);
  Serial.begin(9600); 

  //ensure gripper is at 0 degrees prior to starting 
  setUpGripper();
       
}

void loop() {

  unsigned long current_time = 0;
  unsigned long previous_time = millis();

  bool flag = true;

  testGripper();

  while(flag == true){
    
  }
  
  ///////////////////////////////////////////////////////////////WINCH AND ROVER TO GROUND////////////////////////////////////////////////////////////////////
  //activate winch mmotor to drop rover down

  //time delay to let rover drop down (tests and record how long it takes for rover to drop)

  ///////////////////////////////////////////////////////////////DRIVE TO PAYLOAD////////////////////////////////////////////////////////////////////

  //activate the motor wheels 
  runMotor(20); //friction of ball bearings needs consideration, as it will affect the speed

  ///////////////////////////////////////////////////////////////PICK UP PAYLOAD////////////////////////////////////////////////////////////////////

  //constantly flag LDR sensor for any changes
  //if there is a change with first LDR sensor 
    //slow down

  //second LDR sensor change
    //stop

  //activate DC(servo)motor to grip the payload => measure time to rotate DC motor 

  //rotate the servo motor

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
