/*
  DHT22 Basic Demonstration
  DHT22-Basic-Demo.ino
  Demonstrates functions of DHT22 Digital Temperature & Humidity Sensor
  Displays results on Serial Monitor

  DroneBot Workshop 2017
  http://dronebotworkshop.com
*/

// Include DHT Libraries from Adafruit
// Dependant upon Adafruit_Sensors Library

#include "DHT.h";

// Define Constants

#define DHTPIN 7     // DHT-22 Output Pin connection
#define DHTTYPE DHT22   // DHT Type is DHT 22 (AM2302)

// Initialize DHT sensor for normal 16mhz Arduino

DHT dht(DHTPIN, DHTTYPE);


// Define Variables

float hum;  //Stores humidity value
float temp; //Stores temperature value

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(2000);  // Delay so sensor can stabalize

  hum = dht.readHumidity();  // Get Humidity value
  temp = dht.readTemperature(); // Get Temperature value

  // Print temperature and humidity values to serial monitor

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");

}
