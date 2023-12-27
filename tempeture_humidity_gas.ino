const int ledPin = 13;
const int digitalPin = 7;
const int analogPin = A0;


#include "MQ7.h"

MQ7 mq7(A1,5.0);

#include <dht.h> 
#define DHT11_PIN 2 //pin number: DHT11 sensor is connected

dht DHT;

int digitalVal;
int analogVal; 

void setup(){
 	Serial.begin(9600);
 	pinMode(ledPin, OUTPUT);
 	pinMode(digitalPin, INPUT);
 	Serial.println(F("Flame Sensor Initialized"));
}

void loop(){ 
  Serial.println("debut");
 	readSensor();
  Serial.println("fin");
 	delay(5000);
}

void readSensor(){
 	// Read the digital interface
 	digitalVal = digitalRead(digitalPin);
 	if (digitalVal == LOW){
 			digitalWrite(ledPin, HIGH);
 			Serial.println(F(" 			-> Flame detected"));
 	}else{
 			digitalWrite(ledPin, LOW); 
 	}

 	// Read the analog interface
 	analogVal = analogRead(analogPin);
 	Serial.print(F("Sensor Flame Value "));Serial.println(analogVal);
 	Serial.print(F("digitalPin Flame Value "));Serial.println(digitalVal);
  
  Serial.print(F("Sensor Gaz "));
  Serial.println(mq7.getPPM());

    int chk = DHT.read11(DHT11_PIN);

  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);

}

