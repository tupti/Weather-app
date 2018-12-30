#include <DHT.h>;

#define DHTPIN 7     
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE); // Initialize DHT sensor for normal 16mhz Arduino

float actualHumidity;  
float actualTemperature;
float lastHumidity;
float lastTemperature; 

const int ledPin = 2;
const int buttonPin = 4;
int lastButtonState = LOW;

void setup()
{
  Serial.begin(9600);
  dht.begin();
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop()
{
  actualHumidity = dht.readHumidity();
  actualTemperature = dht.readTemperature();
  int actualButtonState = digitalRead(buttonPin);

if ( lastHumidity != actualHumidity || lastTemperature != actualTemperature || (actualButtonState == HIGH && lastButtonState == LOW)){  
  
  
  if ( lastHumidity != actualHumidity || lastTemperature != actualTemperature) {
    lastTemperature = actualTemperature;
    lastHumidity = actualHumidity;
  }
  
  if (actualButtonState == HIGH && lastButtonState == LOW) {
       digitalWrite(ledPin, !digitalRead(ledPin));   
  }

  
    lastButtonState = actualButtonState;

    //Printing
    Serial.print("actualHumidity:");
    Serial.print(actualHumidity); // in %
    Serial.print("actualTemperature:");
    Serial.print(actualTemperature); // in Celsius
    Serial.print("LED:"); Serial.println(digitalRead(ledPin));
 
    
 }
  
}
