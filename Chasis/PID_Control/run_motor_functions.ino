void motor_setup(){
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}

void run_motor(char state) //high = 1, low = 0
{  
  switch(state){
    case 'f':{
      digitalWrite(in1, LOW);
      digitalWrite(in2, HIGH);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      break;
    }
    
    case 'b':{
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, HIGH);
      digitalWrite(in4, LOW);
      break;
    }
    case 's':{
      digitalWrite(in1, LOW);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, LOW);
      break;      
    }    
  }

  //set speed
  analogWrite(enA, motor_duty_cycle);
  analogWrite(enB, motor_duty_cycle);
}
