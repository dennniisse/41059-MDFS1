/* DIGITAL PINS
 *  1
 *  2 Interrupt encoder
 *  3 Interrupt encoder
 *  4 Encoder
 *  5 E2 RHSMotor2
 *  6 Encoder 
 *  7 hoizontalServo
 *  8 M2 RHSMotor2
 *  9 winch
 *  10 
 *  11 E1 LHSMotor1
 *  12 M1 LHSMotor1
 *  13
*/

/* ANALOGUE PINS
 *  A0: LDR1
 *  A1: LDR2
*/

#include <Servo.h>
Servo servo_gripper;
const int winch = 9;
const int verticalServo = 7;

//drive_control
//LHS Motor 1
const int E1 = 11;
const int M1 = 12;

//RHS Motor 2
const int E2 = 5;
const int M2 = 8;

//LDR Sensors
#define LDR1 A0
#define LDR2 A1

int LDR1_val;
int LDR2_val;

//encoder

//limit switch

//functions
void myDelay(unsigned long to_delay);
void setMotor(void);
void runMotor(unsigned int speed);
void setEncoder(void);
void setUpGripper(void);
void detectPayLoad(void);

bool servo_flag = false;
bool slow_detection = false;
bool stop_detection = false;

int angle;

void setup() {

  setMotor();
  servo_gripper.attach(verticalServo);
  Serial.begin(9600); 

  //ensure gripper is at 0 degrees prior to starting 
  setUpGripper(); 
       
}

void loop() {

  unsigned long current_time = 0;
  unsigned long previous_time = millis();

  //bring motor down to ground
  runMotor(50);

  //rover drive to wheel
  while(slow_detection == false){  //while the trip wire has not been triggered
    //keep polling for change in the trip wire 
    //do nothing but poll
  }  
  myDelay(100);
  runMotor(10);  //if trip wire has been triggered, the program will leave the while loop and hence we slow the motor down, prevents crashing into the wheel

  while(stop_detection == false){
    //poll for second trip wire 
  }
  myDelay(100);
  runMotor(0); 

  
  //rover pick up wheel
  
  //gripper move up so the wheel doesn't drag on the ground
  moveGripperVert(servo_flag); 
  myDelay(100);  

  //rover return to base: two choices do we want the roller winch to drag the rover back or does rover reverse back 

  //rover release wheel 
}
