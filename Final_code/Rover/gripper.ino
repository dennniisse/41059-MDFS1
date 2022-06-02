void setUpGripper(void){
  
  
}

void moveGripperVert(bool& servo_flag){
  if(servo_flag == false ){
  servo_gripper.write(0);
  myDelay(1000);
  servo_gripper.write(90);
  myDelay(1000);
  servo_flag = true;
  }
}

void detectPayLoad(void){
//  LDR1_val = analogue.read(LDR1);
//  LDR2_val = analog.read(LDR2);

  if(LDR1_val < 500)
  {
    // Do Something
      if(LDR2_val < 500)
      {
        
      }
  }
}

void testGripper(void){
  int angle_gripper = servo_gripper.read();
  //int angle_goal = angle_gripper - 15;
  Serial.print("Gripper angle: ");
  Serial.println(angle_gripper);
  //Serial.print("Gripper goal: ");
  //Serial.println(angle_goal);
  
  //servo_gripper.write(angle_goal);
}
