void setUpGripper(void){
  servo.write(170);      
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


void securePayLoad(bool state){
  switch(state)
  {
    case true:  //release CCW
    {
      digitalWrite(inA, HIGH);
      digitalWrite(inB, LOW);
      break;
    }
    case false: //close CW
    {
      digitalWrite(inA, LOW);
      digitalWrite(inB, HIGH);
      break;
    }

  }
}


void servoLift(void){  //false = down, true = up
  int current_angle = servo.read();
  
  servo.write(140);
}
