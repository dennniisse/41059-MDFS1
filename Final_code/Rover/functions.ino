void myDelay(unsigned long int to_delay){ //delay using millis, works as a normal delay 
  unsigned long current_time = 0;
  unsigned long previous_time = millis();
  if(current_time - previous_time < to_delay)
  {
    //nothing
    current_time = millis();
  }
}
