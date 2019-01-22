int data = 0;
int c =0;

void setup() {
  Serial.begin(9600);
  Serial.println("Bluetooth ready");
}

void loop() {
  while(Serial.available()>0) {
    data = Serial.read();
  }
  

  
  if(c%400==0) {
    Serial.println(data);
  }
    
  
  c++;
}


