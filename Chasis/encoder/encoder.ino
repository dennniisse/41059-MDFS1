/* https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
 *  Purpose of an interrupt is to receive inputs while not having a constant poll checking for inputs 
 *  ISR are short and fast and only one interrupt can run at a time 
*/


//set motor speed
#define motor_duty_cycle 100
//variables for motor state

int ON = 1;
int OFF = 0; 
//Lowest to speed 50 
//Motor A
int enA = 11;
int in1= 10;
int in2 = 9;

//Motor B
int enB = 6;
int in3 = 7;
int in4 = 8;

//motor needs an interrupt pin (these are pin 2 and 3 on uno boards, their interrupt numbers are respectively 0,1)
const byte encoder0pinA = 2;
const byte encoder0pinB = 4;
byte encoder0PinALast;
int duration;
boolean Direction;

void setup()
{
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //To read encoder, serial port needs to be at 57600 baud 
  Serial.begin(57600);
  EncoderInit();
}

void loop()
{
  run_motor(1);
  Serial.print("Pulse: ");
  Serial.println(duration);
  duration = 0;
  delay(100);
}

void EncoderInit()
{
  //this is just use the void set up
  //set direction as true, which is forward as a default
  Direction = true;
  //set the pinMode for pinB
  pinMode(encoder0pinB, INPUT);
  /*attachInterrupt(intterup number, ISR, mode)
   * ISR: refers to the function we've created to create an interrupt
   * mode: defines when interrupt is triggered
            * CHANGE: trigger interrupt whenever the pin changes value 
  */
  attachInterrupt(digitalPinToInterrupt(encoder0pinA),wheelSpeed,CHANGE);
  
  
}

void wheelSpeed()
{
  int Lstate = digitalRead(encoder0pinA);
  if((encoder0PinALast == LOW) && Lstate==HIGH)
  {
    int val = digitalRead(encoder0pinB);
    if(val == LOW && Direction)
    {
      Direction = false; //Reverse
    }
    else if(val == HIGH && !Direction)
    {
      Direction = true;  //Forward
    }
  }
  encoder0PinALast = Lstate;

  if(!Direction)  duration++;
  else  duration--;

}

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
