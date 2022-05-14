#include <PID_v1.h>

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

//PID
double speed_LHS, speed_RHS;  //Power suppleid to the motor PWM value 
double duration_LHS, duration_RHS;
double Setpoint, Setpoint_L, Setpoint_R; //we only need one
double Kp = 0.6, Ki = 5, Kd = 0;
PID PID_LHS(&duration_LHS, &speed_LHS, &Setpoint_L, Kp, Ki, Kd, DIRECT);
PID PID_RHS(&duration_RHS, &speed_RHS, &Setpoint_R, Kp, Ki, Kd, DIRECT);
boolean result_LHS, result_RHS;

//functions
void myDelay(unsigned long to_delay);
void setMotor(void);
void runMotor(void);
void setEncoder(void);
void encoderRead_LHS(void);
void setUpGripper(void);
void detectPayLoad(void);

void setup() {
  Serial.begin(9600); 

  //PID set up
  Setpoint = 50;
  Setpoint_L = Setpoint;
  Setpoint_R = Setpoint;
  PID_LHS.SetMode(AUTOMATIC); //PID mode is automatic, hence will update on its own
  PID_LHS.SetSampleTime(100); //how much the PID will sample incoming data, which is every 100ms 
  PID_RHS.SetMode(AUTOMATIC); //PID mode is automatic, hence will update on its own
  PID_RHS.SetSampleTime(100); //how much the PID will sample incoming data, which is every 100ms 
  
  //other setup
  setMotor();
  setEncoder();

       
}

void loop() {

  unsigned long current_time = 0;
  unsigned long previous_time = millis();
  
  //bring motor down to ground
  runMotor();   
  result_LHS = PID_LHS.Compute();
  result_RHS = PID_RHS.Compute();
  
  if(result_LHS){
    Serial.print("Pulse_LHS: ");
    Serial.println(duration_LHS);
    duration_LHS = 0;
  }

  if(result_RHS){
    Serial.print("Pulse_RHS: ");
    Serial.println(duration_RHS);
    duration_LHS = 0;
  }
  
}
