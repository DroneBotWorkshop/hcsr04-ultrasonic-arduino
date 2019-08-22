/*
  HC-SR04 in 3-Wire Mode with Temp and Humidity Demonstration
  HC-SR04-3Wire-Temp-Humid-Demo.ino
  Demonstrates enhancements of HC-SR04 Ultrasonic Range Finder
  With DHT22 Temperature and Humidity Sensor
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include DHT Libraries from Adafruit
// Dependant upon Adafruit_Sensors Library
#include "DHT.h";

// Include NewPing Library
#include "NewPing.h"

// Define Constants

#define DHTPIN 7       // DHT-22 Output Pin connection
#define DHTTYPE DHT22   // DHT Type is DHT 22 (AM2302)
#define TRIGGER_PIN  10  // Trigger and Echo both on pin 10
#define ECHO_PIN     10
#define MAX_DISTANCE 400

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Define Variables

float hum;    // Stores humidity value in percent
float temp;   // Stores temperature value in Celcius
float duration; // Stores HC-SR04 pulse duration value
float distance; // Stores calculated distance in cm
float soundsp;  // Stores calculated speed of sound in M/S
float soundcm;  // Stores calculated speed of sound in cm/ms
int iterations = 5;

// Initialize DHT sensor for normal 16mhz Arduino

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin (9600);
  dht.begin();
}

void loop()
{

  delay(2000);  // Delay so DHT-22 sensor can stabalize

  hum = dht.readHumidity();  // Get Humidity value
  temp = dht.readTemperature(); // Get Temperature value

  // Calculate the Speed of Sound in M/S
  soundsp = 331.4 + (0.606 * temp) + (0.0124 * hum);

  // Convert to cm/ms

  soundcm = soundsp / 10000;

  duration = sonar.ping_median(iterations);

  // Calculate the distance
  distance = (duration / 2) * soundcm;

  // Send results to Serial Monitor

  Serial.print("Sound: ");
  Serial.print(soundsp);
  Serial.print(" m/s, ");
  Serial.print("Humid: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.print(" C, ");
  Serial.print("Distance: ");

  if (distance >= 400 || distance <= 2) {
    Serial.print("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.print(" cm");
    delay(500);
  }

  Serial.println(" ");
}
