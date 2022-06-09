/* Wired the two motors as one. 
 *  Motor1 spins the other direction in comparison to Motor2
 *  Motor1 wires has been connected to Motor2 in such a way that it swaps the direction 
*/
#include <DualVNH5019MotorShield.h>

DualVNH5019MotorShield md;

//M1 Zipline
//M2 Winch

/////////////////////////////////////////////////////////////////////////////////////
int winch_delay = 2000; //wait for winch to move up
int zipline_delay = 15000;  //time to cross
int ziplin_wait_s = 30000;  //
int delivery_delay = 5000;  //wait for the gripper to open 
//
//
/////////////////////////////////////////////////////////////////////////////////////
void setup() {
  md.init();
}

void loop() {  

  //myDelay(10000);  //wait for rover to grab payload
  md.setM2Speed(400);
  md.setM1Speed(400);

  myDelay(winch_delay);//wait for for winch to move up 

  md.setM2Speed(0); //stop the winch moving !! DUH

  md.setM1Speed(400); //move across wire

  myDelay(zipline_delay); //time to cross

  md.setM1Speed(0); //stop zipline from moving DUH

  myDelay(delivery_delay);  //wait for gripper to deliver payload

  md.setM1Speed(-400);  //return to start

  myDelay(zipline_delay); 

  md.setM1Speed(0); //stop zipline, TAH-DAH!
  
  exit(0);
}
