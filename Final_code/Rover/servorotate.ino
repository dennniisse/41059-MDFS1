#include <Servo.h>
Servo servorotate;

const int ldrPin = A0; //input of LDR2 (the second LDR)
int ldrStatus = 300; //setup the LDR status to a value above 200

void setup() {
  // put your setup code here, to run once:
  setUpServo();
}

void loop() {
  // put your main code here, to run repeatedly:
  servoGripper();
}

void setUpServo(void){
  servorotate.attach(9); //attach signal pin of servo to pin 9 of arduino - pin 10 because Servo lib only supports on pins 9 and 10
  servorotate.write(0); //initial position of gripper is 0 degrees
  pinMode(ldrPin, INPUT);
}

void servoGripper(void){
  //ldrStatus = analogRead(ldrPin);
  //retrieval of wheel
  //if (ldrStatus <= 200) {         //condition is if the second LDR sensor is has low light
    //servorotate.write(60); //rotate to 60 degrees for transportation
    //delay(1000);  //1 second delay
  //}

  //else { //LDRs are still <=200
    //Continue holding the wheel 60 degrees in the air
  //}

  servorotate.write(60);
  delay(1000);  
  
}
