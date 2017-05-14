#define trigPin1 8
#define echoPin1 12

long duration, distance, UltraSensor;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
}

void loop() {
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
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
delay(100);
}
