void setEncoder(){
  pinMode(en1B,INPUT);
  attachInterrupt(1, encoderRead, CHANGE); //the function will interrupt whenever there's changes to the encoder value 
}

void encoderRead(){
  duration++; 
}
