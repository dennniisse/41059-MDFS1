//motor
unsigned volatile int motor_duty_cycle = 100;
//Motor A
const byte enA = 11;
const byte in1 = 10;
const byte in2 = 9;
//Motor B
const byte enB = 6;
const byte in3 = 7;
const byte in4 = 8;

//encoder 
//encoder 1
const byte enc0pinA = 2;
const byte enc0pinB = 4;
//encoder 2
const byte enc1pinA = 3;
const byte enc1pinB = 5;


void setup() {
  motor_setup();

  Serial.begin(57600);

}

void loop() {
  run_motor('f');
  delay(10000);
}
