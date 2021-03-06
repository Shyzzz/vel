#define trigPin1 8
#define echoPin1 12
long duration, distance, UltraSensor;
#include <PCD8544.h>
#include <SoftwareSerial.h>
 
//SIM800 TX is connected to Arduino D8
#define SIM800_TX_PIN 11
 
//SIM800 RX is connected to Arduino D7
#define SIM800_RX_PIN 10
 
//Create software serial object to communicate with SIM800
SoftwareSerial serialSIM800(SIM800_TX_PIN,SIM800_RX_PIN);
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };
static PCD8544 lcd;
void setup() {
  //Begin serial comunication with Arduino and Arduino IDE (Serial Monitor)
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(A0,INPUT); pinMode(13,OUTPUT);
  pinMode(9, OUTPUT);
  beep(50);
  beep(50);
  beep(50);
  delay(1000);
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);

  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
  while(!Serial);
   
  //Being serial communication witj Arduino and SIM800
  serialSIM800.begin(9600);
  delay(1000);
   
  Serial.println("Setup Complete!");
  Serial.println("Sending SMS...");
   
  //Set SMS format to ASCII
  serialSIM800.write("AT+CMGF=1\r\n");
  delay(1000);
 
  //Send new SMS command and message number
  serialSIM800.write("AT+CMGS=\"7200416770\"\r\n");
  delay(1000);
   
  //Send SMS content
  serialSIM800.write("SOS");
  delay(1000);
   
  //Send Ctrl+Z / ESC to denote SMS message is complete
  serialSIM800.write((char)26);
  delay(1000);
     
  Serial.println("SMS Sent!");
}
void loop() {
  // Just to show the program is alive...
  static int counter = 0;

  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("Vehicle Cabin Safety Alert  System!");

  // Write the counter on the second line...
  lcd.setCursor(0, 4);
  lcd.print(counter, DEC);
  lcd.write(' ');
  lcd.write(0);  // write the smiley

  // Use a potentiometer to set the LCD contrast...
  // short level = map(analogRead(A0), 0, 1023, 0, 127);
  // lcd.setContrast(level);

  delay(200);
  counter++;
  if(analogRead(A0)){
    (digitalWrite(13,LOW));
    Serial.println("CO Detected");
   // lcd.print("Vehicle Cabin Safety Alert  System CO Detected!");
    delay(2000);
    }
SonarSensor(trigPin1, echoPin1);
UltraSensor = distance;
Serial.println(UltraSensor);
}

void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
s  analogWrite(9, 20);      // Almost any value can be used except 0 and 255
                           // experiment to get the best tone
  delay(delayms);          // wait for a delayms ms
  analogWrite(9, 0);       // 0 turns it off
  delay(delayms);          // wait for a delayms ms   
}  


