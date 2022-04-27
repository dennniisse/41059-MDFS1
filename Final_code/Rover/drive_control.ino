
void setMotor(void){
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);  
}

void runMotor(unsigned int speed){
  //Motors are turned on
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  

  //set speed
  analogWrite(E1, speed); 
  analogWrite(E2, speed+2);
}
