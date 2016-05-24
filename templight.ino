// Templight
// Dirk Heiden, 2016
// BMP085 verbinden
// Verbinde VCC an 3.3V
// Verbinde GND to Ground
// Verbinde SCL an Analog 5 (i2c clock)
// Verbinde SDA an Analog 4 (i2c data) 
// Adafruit Neopixel verbinden

#include <Wire.h>
#include <Adafruit_BMP085.h>
#include <Adafruit_NeoPixel.h>

#define PIN            4
#define NUMPIXELS      12

Adafruit_BMP085 bmp;
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
  
void setup() {
	Serial.begin(9600);
	if (!bmp.begin()) {
		Serial.println("Es ist kein Sensor gefunden worden!");
	while (1) {}
  }
    pixels.begin();
}
 
void loop() {

	int red= 0;
	int green= 0;
	int blue= 0;

// Beginn der Schleife

	for(int i=0;i<NUMPIXELS;i++){

	float temp = (float)bmp.readTemperature();

	Serial.print(temp,1);
	Serial.println();

// Bestimmt den Anteil an Rot

	if(temp<=-20){
		red=204;}

	else if(temp>-20&&temp<=-15){
		red = map(temp, -20, -15, 204, 255);}

	else if(temp>-15&&temp<=-10){
		red = map(temp, -15, -10, 255, 0);}

	else if(temp>-10&&temp<=-5){
		red = map(temp, -10, -5, 0, 102);}

	else if(temp>-5&&temp<=-1){
		red = map(temp, -5, -1, 102, 153);}

	else if(temp>-1&&temp<=0){
		red = map(temp, -1, 0, 153, 255);}

	else if(temp>0&&temp<=1){
		red = map(temp, 0, 1, 255, 204);}

	else if(temp>1&&temp<=5){
		red = map(temp, 1, 5, 204, 102);}

	else if(temp>5&&temp<=10){
		red = map(temp, 5, 10, 102, 0);}

	else if(temp>10&&temp<=15){
		red = map(temp, 10, 15, 0, 255);}

	else if(temp>15&&temp<=20){
		red = map(temp, 15, 20, 255, 255);}

	else if(temp>20&&temp<=25){
		red = map(temp, 20, 25, 255, 255);}

	else if(temp>25&&temp<=30){
		red = map(temp, 25, 30, 255, 255);}

	else if(temp>30&&temp<=35){
		red = map(temp, 30, 35, 255, 255);}

	else if(temp>35){
		red=255;}

// Bestimmt den Anteil an Gruen

	if(temp<=-20){
		green=0;}

	else if(temp>-20&&temp<=-15){
		green = map(temp, -20, -15, 0, 153);}

	else if(temp>-15&&temp<=-10){
		green = map(temp, -15, -10, 153, 0);}

	else if(temp>-10&&temp<=-5){
		green = map(temp, -10, -5, 0, 153);}

	else if(temp>-5&&temp<=-1){
		green = map(temp, -5, -1, 153, 204);}

	else if(temp>-1&&temp<=0){
		green = map(temp, -1, 0, 204, 255);}

	else if(temp>0&&temp<=1){
		green = map(temp, 0, 1, 255, 255);}

	else if(temp>1&&temp<=5){
		green = map(temp, 1, 5, 255, 255);}

	else if(temp>5&&temp<=10){
		green = map(temp, 5, 10, 255, 255);}

	else if(temp>10&&temp<=15){
		green = map(temp, 10, 15, 255, 255);}

	else if(temp>15&&temp<=20){
		green = map(temp, 15, 20, 255, 153);}

	else if(temp>20&&temp<=25){
		green = map(temp, 20, 25, 153, 0);}

	else if(temp>25&&temp<=30){
		green = map(temp, 25, 30, 0, 0);}

	else if(temp>30&&temp<=35){
		green = map(temp, 30, 35, 0, 153);}

	else if(temp>35){
		green=153;}

// Bestimmt den Anteil an Blau

	if(temp<=-20){
		blue=153;}

	else if(temp>-20&&temp<=-15){
		blue = map(temp, -20, -15, 153, 255);}

	else if(temp>-15&&temp<=-10){
		blue = map(temp, -15, -10, 255, 255);}

	else if(temp>-10&&temp<=-5){
		blue = map(temp, -10, -5, 255, 255);}

	else if(temp>-5&&temp<=-1){
		blue = map(temp, -5, -1, 255, 255);}

	else if(temp>-1&&temp<=0){
		blue = map(temp, -1, 0, 255, 255);}

	else if(temp>0&&temp<=1){
		blue = map(temp, 0, 1, 255, 153);}

	else if(temp>1&&temp<=5){
		blue = map(temp, 1, 5, 153, 51);}

	else if(temp>5&&temp<=10){
		blue = map(temp, 5, 10, 51, 0);}

	else if(temp>10&&temp<=15){
		blue = map(temp, 10, 15, 0, 0);}

	else if(temp>15&&temp<=20){
		blue = map(temp, 15, 20, 0, 51);}

	else if(temp>20&&temp<=25){
		blue = map(temp, 20, 25, 51, 0);}

	else if(temp>25&&temp<=30){
		blue = map(temp, 25, 30, 0, 255);}

	else if(temp>30&&temp<=35){
		blue = map(temp, 30,35, 255, 255);}

	else if(temp>35){
		blue=255;}

// Sendet den berechneten RGB-Wert an die jeweilige LED

    pixels.setPixelColor(i, pixels.Color(red,green,blue));
    pixels.show();

    Serial.print("Pixel: ");
    Serial.print(i);
    Serial.println();
	Serial.print("RGB-Wert: ");
	Serial.print(red,green,blue);
	Serial.println();
    
    delay(10000);
    }
}
