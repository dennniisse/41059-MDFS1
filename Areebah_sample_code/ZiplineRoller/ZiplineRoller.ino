//Zipline Roller as a whole
//goToDeposit
  //time delay, then turn on motors forward() for a certain time -- while loops
  //after certain time, stop.
//waitTime
  //wait a certain time
//goBack
  //wait certain time, turn on reverse() for a certain time
  //after certain time, stop.

#include <DualVNH5019MotorShield.h>
DualVNH5019MotorShield md;

#include <Timer.h>
Timer timer;

int crossTime = 40000;  //chosen 40 seconds for now
int waitTime = 3000;    //chosen 3 seconds for now


void setUpRoller(void);

void setup() {
  // put your setup code here, to run once:
  setUpRoller();
}

void loop() {
  // put your main code here, to run repeatedly:
  //run forward movement
  goToDeposit();
  //wait for rover to complete its mission
  waitPeriod();
  //run reverse movement
  //do i need below here, since I called for goBack in waitPeriod????
  //goBack();
}

//set up how??? i think pins and start timer
void setUpRoller(void) {
  //setup pins??
  md.init();  //setup of pinMOdes and timer1?
  timer.start();
}

void goToDeposit(void) {
  //set a crossTime (should be same for goToDeposit and goBack)
  //until time counted is crossTime, move the wheels forward
  //stop movement of wheels when time = crossTime
    
  while (timer.read() < crossTime) {
    md.setM1Speed(400); //forward movement
  }
}

void waitPeriod(void) {
  //if the timer.read() = crossTime + waitTime
  
  if (timer.read() == (crossTime + waitTime)) {
    goBack();
  }
}

void goBack(void) {
  //until movement of wheels when time = crossTime + waitTime + crossTime
  //stop wheels
  while (timer.read() < (crossTime + waitTime + crossTime)) {
    md.setM1Speed(-400);  //reverse movement
  }
  timer.stop();
}
