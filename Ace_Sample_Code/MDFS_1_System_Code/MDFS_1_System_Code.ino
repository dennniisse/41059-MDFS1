/* Skeleton Code for MDFS_1 System (ver 1.0)
 *  Copy and Paste Functions if multiple sensors are required
 *  
 *  Change the names accordingly for its specific purpose e.g.
 *  gripperServo,gripperSensor,etc.
 *  
 */

// Include Libraries here lmao
#include <Servo.h> // Servo Library for controlling Servos
#include <Wire.h> // Wire Library for I2C Communication

// Define Global Variables
#define deBounce 150

// Limit Switch Variables
#define Switch 2
int SwitchState;
int lastSwitchState;
unsigned long SwitchTimer;

// Proximity Sensor Variables
#define Sensor_A 3
int SensorState;
int lastSensorState;
unsigned long SensorTimer;

// Wheel Motor Variables, Change pin number accordingly
#define L_MotorA 8
#define L_MotorB 7
#define R_MotorA 5
#define R_MotorB 4
#define L_Enable 9
#define R_Enable 3


/* Check Switch Function - just checks whether the switch
 * has been activated. If so, the value will be stored as
 * true or false (1 or 0) for the particular switch until
 * it has been reset after a task is completed.
 */
void checkSwitch()
{
  // Read the value of the switch pin, store value at variable SwitchState
  SwitchState = digitalRead(Switch);

  // Checks if switch has been toggled before
    if(SwitchState == 1 && SwitchState != lastSwitchState)
    {
      // Debounces so it doesnt increment the last state greater than 1
      if(millis() - SwitchTimer >= deBounce)
      {
        // Resets Timer variable to latest millis value
        SwitchTimer = millis();
        // Basically says it has been pressed
        lastSwitchState += 1; // Reset to Zero after completing a task
      }
    }
}

/* Check Sensor Function - just checks whether the proximity
 * sensor detects something / or doesnt (up to how we wanna 
 * use it). If so, the value will be stored as true or false
 * (1 or 0) for the particular switch until it has been reset
 * after a task is completed.
 */
void checkSensor_A()
{
  // Read the value of the sensor pin, store inverted value at variable SensorState
  SensorState = !digitalRead(Sensor_A);

  // Checks if sensor has detected something before
    if(SensorState == 1 && SensorState != lastSensorState)
    {
      // Debounces so it doesnt increment the last state greater than 1
      if(millis() - SensorTimer >= deBounce)
      {
        // Resets Timer variable to the latest millis value
        SensorTimer = millis();
        // Basically says it has been detected
        lastSensorState += 1; // Reset to Zero after completing a task
      }
    }
}

/* runMotors Function - just so its easier to write code lol
 * But to use, just call function in main loop: example -
 * runMotors(255,255,1,0,1,0)
 * Both wheels will run at PWM value of 255, same direction
 * (hopefully).
 */
void runMotors(int LE, int RE, int LM_A, int LM_B, int RM_A, int RM_B)
{
  analogWrite(L_Enable, LE); // Write PWM Value to L_Enable pin
  analogWrite(R_Enable, RE); // Write PWM Value to R_Enable pin
  digitalWrite(L_MotorA,LM_A); // Write HIGH/LOW to L_MotorA pin
  digitalWrite(L_MotorB,LM_B); // Write HIGH/LOW to L_MotorB pin
  digitalWrite(R_MotorA,RM_A); // Write HIGH/LOW to R_MotorA pin
  digitalWrite(R_MotorB,RM_B); // Write HIGH/LOW to R_MotorB pin
}

/* Setup Function,
 * define pinModes and initialize functions if needed here
 */
void setup() {
  Serial.begin(9600); // For Debugging purposes
    pinMode(Switch, INPUT); // Switch is an Input
    pinMode(Sensor_A, INPUT); // Sensor is an Input
    pinMode(L_MotorA, OUTPUT); // Left Motor A is an Output
    pinMode(L_MotorB, OUTPUT); // Left Motor B is an Output
    pinMode(R_MotorA, OUTPUT); // Right Motor A is an Output
    pinMode(R_MotorB, OUTPUT); // Right Motor B is an Output
    pinMode(L_Enable, OUTPUT); // Left Enable is an Output (PWM Control)
    pinMode(R_Enable, OUTPUT); // Right Enable is an Output (PWM Control)

}

void loop() {
  checkSwitch(); // Call checkSwitch Function
  checkSensor_A(); // Call checkSensor_A Function

  // Run the left and right motors at 255 PWM Value at the 1,0 direction.
  runMotors(100,100,1,0,1,0);

  //Delay for 1s before stopping.
  delay(1000);
  // Stops the Motors as all values is zero
  runMotors(0,0,0,0,0,0);
  // Serial Print for debugging purposes.
  Serial.print("Switch Value:"); 
  Serial.println(lastSwitchState);
  Serial.print("Sensor Value:"); 
  Serial.println(lastSensorState);

  // Optional delay for the Serial print 
  delay(1000);


}
