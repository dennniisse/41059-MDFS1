#define signal_pin A0
int data_value;

void setup() {
  Serial.begin(115200);
    pinMode(signal_pin, INPUT);
}

void loop() {
  
  data_value = digitalRead(signal_pin);
  Serial.println (data_value);
  delay(500);

}
