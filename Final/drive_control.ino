void setMotor(void){
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);  
}

void runMotor(unsigned int speed){
  //Motors are turned on
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  

  //set speed
  analogWrite(E1, speed+5); 
  analogWrite(E2, speed);
}

void gripperActivate(Servo& servo){
  servo.write(0);
  myDelay(1000);
  servo.write(45);
  myDelay(1000);
  servo.write(90);
  myDelay(1000);
  servo.write(135);
  myDelay(1000);
  servo.write(180);
  myDelay(1000);
}
