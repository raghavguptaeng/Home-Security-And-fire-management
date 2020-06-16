
#include <dht.h>
#define dht_apin A4 
dht DHT;
const int buzzerPin = 4;
const int flamePin = A0;
const int red = 7;
const int blue = 5;
const int green = 6;
int sensorPin = A5; // select the input pin for LDR
int Flame = HIGH;
int sensorValue;
const int relay = 8;
void setup() 
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(flamePin, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    int temp = DHT.temperature;
    Serial.print((temp)); 
    Serial.println("C  ");
  Flame = digitalRead(flamePin);
  if (Flame== HIGH)
  {
    Serial.println("Fire!!!");
    digitalWrite(buzzerPin, HIGH);
    digitalWrite(blue , HIGH);
    digitalWrite(relay , HIGH);
  }
  else
  {
    Serial.println("No worries");
    digitalWrite(buzzerPin, LOW);
    digitalWrite(relay , LOW);
    digitalWrite(red , LOW);
    digitalWrite(green , HIGH);
  }
  sensorValue = analogRead(sensorPin); // read the value from the sensor
  Serial.println(sensorValue); //prints the values coming from the sensor on the Screen
  if(sensorValue<822){
    digitalWrite(red , HIGH);
    //digitalWrite(buzzerPin, HIGH);
  }
  else{
    digitalWrite(red , LOW);
    digitalWrite(green , LOW);
    digitalWrite(blue , HIGH);
    //digitalWrite(buzzerPin, LOW);
  }
  delay(5000);
}
