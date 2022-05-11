double m_speed;
//drive_control
//LHS Motor 1
const int E1 = 11;
const int M1 = 12;

//RHS Motor 2
const int E2 = 5;
const int M2 = 8;

//encoder & PID
const byte en1A = 3; //Int pin 0, LHS
const byte en1B = 4; //Int pin 3, RHS 
const byte en2A = 2; //Int pin 0, LHS
const byte en2B = 6; //Int pin 3, RHS 
int duration;

void setup()
{
  Serial.begin(9600);//Initialize the serial port
  EncoderInit();//Initialize the module
  setMotor();
  runMotor(30);
}

void loop()
{
  Serial.print("Pulse:");
  Serial.println(duration);
  duration = 0;
  delay(100);
}

void EncoderInit()
{  
  pinMode(en1B,INPUT);
  pinMode(en2B,INPUT);
  attachInterrupt(0, wheelSpeed, CHANGE);
}

void wheelSpeed()
{
  duration++; //the faster the wheel the greater the value  
}
