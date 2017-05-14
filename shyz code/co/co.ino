void setup() {
Serial.begin(9600);
pinMode(A0,INPUT); pinMode(13,OUTPUT);
}

void loop(){
  if(analogRead(A0)){
    (digitalWrite(13,LOW));
    Serial.println("CO Detected");
    delay(2000);
    }
  else{
 Serial.println("CO Not Detected");
  delay(1000);}

}
