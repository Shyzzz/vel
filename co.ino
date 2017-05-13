void setup() {
Serial.begin(9600);
pinMode(10,INPUT); pinMode(13,OUTPUT);
}

void loop(){
  if(digitalRead(11)){
    (digitalWrite(13,HIGH));
    Serial.println("CO Detected");
    delay(2000);
    }
  else{
 Serial.println("CO Not Detected");
  delay(1000);}

}
