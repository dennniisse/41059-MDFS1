/* Wired the two motors as one. 
 *  Motor1 spins the other direction in comparison to Motor2
 *  Motor1 wires has been connected to Motor2 in such a way that it swaps the direction 
*/
#include "DualVNH5019MotorShield.h"

DualVNH5019MotorShield md;

void stopIfFault()
{
  if (md.getM1Fault())
  {
    Serial.println("M1 fault");
    while(1);
  }
  if (md.getM2Fault())
  {
    Serial.println("M2 fault");
    while(1);
  }
}

void setup() {
  md.init();

}

void loop() {
  md.setM1Speed(300);
  stopIfFault();
  myDelay(100);
}
