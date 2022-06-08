#include <Servo.h>

Servo servo;
const int verticalServoPin = 9;

void setup() {
  servo.attach(verticalServoPin);
  Serial.begin(9600); 

  //ensure gripper is at 0 degrees prior to starting 
       


}

void loop() {
  int current_angle = servo.read();
  int move_angle = 15;
  bool upDown = true;

  servo.write(70);
  delay(3000);

  Serial.print("Value: ");
  delay(100);
  Serial.println(upDown);
  
  switch(upDown)
  {
    case true:  //case up 
    {
      Serial.print("Up");
      delay(100);
      servo.write(50);
      delay(3000);
      break;
    }

    case false:
    {
      Serial.print("Up");
      delay(100);
      servo.write(current_angle + move_angle);
      break;
    }
  }

  exit (0);

}
