unsigned float data = 0.0f;

void setup() {
  Serial.being(9600);
}

void loop() {
  if(Serial.available()) {
    data = Serial.read();
    Serial.println(data);
  }
}

