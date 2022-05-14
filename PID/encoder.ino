void setEncoder(){
  pinMode(en1B,INPUT);
  pinMode(en2B,INPUT);
  attachInterrupt(1, encoderRead_LHS, CHANGE); //the function will interrupt whenever there's changes to the encoder value 
  attachInterrupt(0, encoderRead_RHS, CHANGE);
}

void encoderRead_LHS(){
  duration_LHS++;
}

void encoderRead_RHS(){
  duration_RHS++;
}
