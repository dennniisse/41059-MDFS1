void setUpGripper(void){
  //angle = servo_gripper.read(); //this causes issues with the wheel motors, might be becuase it's not receiving any data 
  servo_gripper.write(45);
  myDelay(100);
  servo_gripper.write(0); 
  myDelay(100);
  
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
