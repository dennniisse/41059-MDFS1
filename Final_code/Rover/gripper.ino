void setUpGripper(void){
  servo.write(70);      
}

bool detectPayLoad(int LDR){  //this code checks if the LDR has gone below the threshold value
  bool LDR_status = false;
  
  switch(LDR) //depending on input value it detects either LDR1 or LDR2 values 
  {
    case 1:
    {
      LDR1_val = analogRead(LDR1);  //reader LDR values 
      if(LDR1_val < LDR_threshold){
        LDR_status = true;                 
      }
      else{
        LDR_status = false;
      }
      break;          
    }
    case 2:
    {
      LDR2_val = analogRead(LDR2); 
      if(LDR2_val < LDR_threshold){
        LDR_status = true;                 
      }
      else{
        LDR_status = false;
      }   
      break;   
    }
  }
  
  return LDR_status; //it returns whether the wheel has been detected based on true or false statement
}

/*
void securePayLoad(void){
  int current_time = 0;
  int previous_time = millis();
  
  if(secure_payload_bool == true)
  {
    while(current_time - previous_time < motor_delay)
    {
      current_time = millis();
      digitalWrite(inA, HIGH);
      digitalWrite(inB, LOW);       
    }
  }

  myDelay(1500);

  digitalWrite(inA, LOW);
  digitalWrite(inB, LOW); 
  delay(500);   

}
*/

void servoLift(void){  //false = down, true = up
  int current_angle = servo.read();
  
  servo.write(50);
}
