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

int ON = 1;
int OFF = 0; 
//Lowest to speed 100 
//Motor A
int enA = 9;
int in1= 8;
int in2 = 7;

//Motor B
int enB = 3;
int in3 = 4;
int in4 = 5;



void setup() {
  //Set motor pins as output, do not need to read from it
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

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
  digitalWrite(in1, state);
  digitalWrite(in2, LOW);
  digitalWrite(in3, state);
  digitalWrite(in4, LOW);

  //set speed
  analogWrite(enA, motor_duty_cycle);
  analogWrite(enB, motor_duty_cycle);
  
}


void loop()
 
{ 
  run_motor(1);
  delay(10000);
 
}
