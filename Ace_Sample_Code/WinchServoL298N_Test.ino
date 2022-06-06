#include <Servo.h>

Servo servo;

#define inA 10
#define inB 13
#define ldr1 A0
#define ldr2 A1

int state;
int ldr1_val;
int ldr2_val;


void setup() {
 
  pinMode(inA, OUTPUT);
  pinMode(inB, OUTPUT);
  pinMode(ldr1, INPUT);
  pinMode(ldr2, INPUT);

  Serial.begin(9600);
  
  servo.attach(9);

  digitalWrite(inA, LOW);
  digitalWrite(inB, HIGH);
  delay(300);

}

void loop() 
{
  ldr1_val = analogRead(ldr1);
  ldr2_val = analogRead(ldr2);

  Serial.print(ldr1_val);
  Serial.print(",");
  Serial.println(ldr2_val);

  
  /*
  if(state == 0)
  {
    
  }

  
  digitalWrite(inA, HIGH);
  digitalWrite(inB, LOW);
  delay(800);
  digitalWrite(inA, LOW);
  digitalWrite(inB, HIGH);
  delay(1200);
*/

}
