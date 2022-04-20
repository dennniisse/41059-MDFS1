#include <Servo.h>
Servo servo_gripper;
const int servoPin = 9;

//drive_control
//LHS Motor 1
const int E1 = 11;
const int M1 = 12;

//RHS Motor 2
const int E2 = 5;
const int M2 = 8;

//encoder

//limit switch

//functions
void myDelay(unsigned long to_delay);
void setMotor(void);
void runMotor(unsigned int speed);
void setEncoder(void);
void gripperActivate(Servo& servo);

void setup() {

  setMotor();
  servo_gripper.attach(servoPin); //object and hence can't be in other functions we're it isn't initialised 

  Serial.begin(9600); 
}

void loop() {

  unsigned long current_time = 0;
  unsigned long previous_time = millis();

  //bring motor down to ground
  


  //rover drive to wheel
  while(current_time - previous_time <= 5000){
    runMotor(50);
    current_time = millis();
  }
  
  myDelay(1000);
  runMotor(0);

  //rover pick up wheel
  gripperActivate(servo_gripper);

  myDelay(10000);

  //rover drive to destination 
}
