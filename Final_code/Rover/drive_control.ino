void setMotor(void){
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);  

  //servo DC motor
//  pinMode(inA, LOW);
//  pinMode(inB, HIGH);
//  digitalWrite(inA, LOW);
//  digitalWrite(inB, LOW);
}

void runMotor(unsigned int m_speed){
  //Motors are turned on
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  
  //set speed
  analogWrite(E1, m_speed); 
  analogWrite(E2, m_speed);
}
