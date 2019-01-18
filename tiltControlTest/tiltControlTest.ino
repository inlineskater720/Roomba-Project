float data = 0.0f;

void setup() {
  Serial.begin(9600);
  Serial.println("Bluetooth ready");
}

void loop() {
  while(Serial.available()>0) {
    data = Serial.read();
    Serial.println(data);
  }
}


