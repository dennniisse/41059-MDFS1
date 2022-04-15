#include "DualVNH5019MotorShield.h"
DualVNH5019MotorShield md;
int forVel = 500;
int bacVel = -500;
int pauseVel = 0;

#define edgesensorPin 3
int edgesensorVal = 0;
bool edgeDetected;


void setup() 
{
 Serial.begin(9600);
  md.init();
}

void loop() 
{
  Serial.println("Testing Movement Control");

  detectEdge();
  
    forward();
    delay(1000);
    pause();
    delay(2000);
  
    backward();
    delay(1000);
    pause();
    delay(2000);
  
    left();
    delay(1000);
    pause();
    delay(2000);
  
    right();
    delay(1000);
    pause();
    delay(2000);
}


// Movement Functions
void forward()
{
  md.setM1Speed(bacVel);
  md.setM2Speed(bacVel);
}

void backward()
{
  md.setM1Speed(forVel);
  md.setM2Speed(forVel);
}

void left()
{
  md.setM1Speed(bacVel);
  md.setM2Speed(forVel);
}

void right()
{
  md.setM1Speed(forVel);
  md.setM2Speed(bacVel);
}

void pause()
{
  md.setM1Speed(pauseVel);
  md.setM2Speed(pauseVel);
}

void detectEdge()
{
  edgesensorVal = digitalRead(edgesensorPin);

    if(edgesensorVal == 1)
    {
      edgeDetected = true;
    }
    else
    {
      edgeDetected = false;
    }
}
