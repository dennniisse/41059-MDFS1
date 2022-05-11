
void setMotor(void){
  pinMode(E1, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(M2, OUTPUT);  
}

void runMotor(int vroom){
  //Motors are turned on
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  

  //set speed
  analogWrite(E1, vroom); 
  analogWrite(E2, vroom);
}
