#include "dht.h"
#define dht_apin A2 // Analog Pin sensor is connected to
dht DHT;
int sensorValue;
int digitalValue;
int soundSensorPin = A0;  // Sound sensor analog pin
int ledPin = 11;          // LED pin
int moistureSensorPin = A4;

 
void setup(){
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  delay(1000);//Wait before accessing Sensor
   pinMode(13, OUTPUT);
   pinMode(ledPin, OUTPUT); // Set LED pin as output
 
}//end "setup()"
 
void loop(){
  //Start of Program 
 
    DHT.read11(dht_apin);
    Serial.println("DHT11 Humidity & Temperature Sensor starts \n\n");
    Serial.print("Current Humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    Serial.println("------------------------------------------------");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
    Serial.println("Air Quality Sensor Starts");
    sensorValue = analogRead(1); // read analog input pin 1
    Serial.println("The Value Read by MQ135 Sensor\n\n");
  if (sensorValue > 15)
  {
    digitalWrite(13, HIGH);
    Serial.print("The Surrounding Environment is over polluted: ");
    Serial.print(sensorValue, DEC);
    Serial.print("ppm");
    Serial.println();
    Serial.println("------------------------------------------------");
  }
  else
  {
    digitalWrite(13, LOW);
    Serial.print("The Surrounding Environment is less polluted: ");
  Serial.print(sensorValue); // prints the value read
  Serial.print("ppm");
  Serial.println();
  Serial.println("------------------------------------------------");
  }
  Serial.println("Noise Monitoring System Activates\n\n");
  delay(5000); // wait 5seconds for next reading
  int soundLevel = analogRead(soundSensorPin); // Read the sound level                 // Print the sound level to serial monitor

  if (soundLevel >= 35) {  // If the sound level is greater than or equal to 500
    digitalWrite(ledPin, HIGH); // Turn on the LED
     Serial.print("The Environment is subject to a very high noise:");
     Serial.print(soundLevel);
     Serial.print("dB");
     Serial.println();
     Serial.println("------------------------------------------------");
  } else {
    digitalWrite(ledPin, LOW); // Turn off the LED
    Serial.print("The Environment is subject to less noise:");
    Serial.print(soundLevel);
    Serial.print("dB");
    Serial.println();
    Serial.println("------------------------------------------------");
  }
  delay(5000);
   Serial.println("Soil Monitoring System Activates\n\n");
   int moistureLevel = analogRead(moistureSensorPin); 
   // Read the moisture level
   if(moistureLevel>700)
   {
     Serial.println("The Soil is having low moisture content.");
     Serial.println("------------------------------------------------");
   }
   else
   {
     Serial.println(" Don't worry! The soil needs no Irrigation");
     Serial.println("------------------------------------------------");
   }
   Serial.println();
  //Fastest should be once every two seconds.
 
}// end loop()
