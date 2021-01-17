/* TEMPERATURE & HUMIDITY SENSOR
   Program to print humidity and temperature on Serial Monitor

# Connections
  This sensor has 3 pins,
   *  - ve -----> GND
   *  out ------> pin 2
   *  +ve ------> 5V
   
Note : Install and Include the DHT11 library before compiling the code.

*/
//**************************************************************************************************************
#include <DHT.h> //include the library
int dhtPin = 2;

//Create an object of DHT11 type
DHT dht(dhtPin, DHT11);

float humidity;
float tempC;
float tempF;

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(500);
}

void loop() {
//Storing the values  
humidity = dht.readHumidity();
tempC = dht.readTemperature(); //Celsius Temperature
tempF = dht.readTemperature(true); //Fahrenheit Temperature

//Printing the results
Serial.print("Humidity: ");
Serial.print(humidity);
Serial.println(" %");
Serial.print("Temperature: ");
Serial.print(tempC);
Serial.print(" C || ");
Serial.print(tempF);
Serial.println(" F ");
Serial.println();

delay(1000);
}
