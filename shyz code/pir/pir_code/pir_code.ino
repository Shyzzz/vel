void setup() {
  Serial.begin(9600);
  pinMode(8,INPUT); pinMode(13,OUTPUT);

}

void loop(){
  while(digitalRead(11)){
    (digitalWrite(13,HIGH));
    Serial.println("PIR Detected");
    delay(2000);
    }
//    else
//      Serial.println("PIR Not Detected");
  delay(1000);
  }

