//https://www.auselectronicsdirect.com.au/assets/files/TA0052%20Stepper%20Motor%20Controller%20Module.pdf
//wiring
//2 Interrupt pin 
//3~ Interrupt pin 
//4
//5~
//6~
//7
//8
//9~ 
//10~
//11~
//12
//13

//set motor speed
#define motor_duty_cycle 40
//variables for motor state

//Motor 1 (LHS)
const int E1 = 3;     //speed control
const int M1 = 4;     //direction, 0 = forward

//Motor 2 (RHS)
const int E2 = 11;
const int M2 = 12;    //direction, 1 = forward


void setup() {
  //Set motor pins as output, do not need to read from it
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);

  Serial.begin(9600);  

}

/*
 * Function: stop, start, forwards, backwards. 
 * Avoid rotation, much more complicated to calibrate and control
 * Testing has shown that this function will last for 10 seconds, despite the duty cycle inputted
            * To do: research how time is determined 
*/
void run_motor(int state) //high = 1, low = 0
{  
  //Motors are turned on
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  

  //set speed
  analogWrite(E1, motor_duty_cycle);
  analogWrite(E2, motor_duty_cycle);
  
}


void loop()
 
{ 
  run_motor(1);
  delay(10000);
 
}
