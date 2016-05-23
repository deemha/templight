// Templight
// Dirk Heiden, 2016

#include <Wire.h>
#include <Adafruit_BMP085.h>

#include <Adafruit_NeoPixel.h>

//#ifdef __AVR__
//#include <avr/power.h>
//#endif

#define PIN            4

#define NUMPIXELS      12

// BMP085 verbinden
// Verbinde VCC an 3.3V
// Verbinde GND to Ground
// Verbinde SCL an Analog 5 (i2c clock)
// Verbinde SDA an Analog 4 (i2c data) 
// Adafruit Neopixel verbinden

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
    float temp = (float)bmp.readTemperature();
//    int red= 0;
//    int green= 0;
//    int blue= 0;

// Beginn der Schleife

    for(int i=0;i<NUMPIXELS;i++){

// Bestimmt den Anteil an Rot

    if(temp<=-20){
    int red=208;}

    else if(temp>-20&&tempC<=-15){
    red = map(temp, -20, -15, 208, 206);}

    else if(temp>-15&&tempC<=-10){
    red = map(temp, -15, -10, 206, 78);}

    else if(temp>-10&&tempC<=-5){
    red = map(temp, -10, -5, 78, 72);}

    else if(temp>-5&&tempC<=-1){
    red = map(temp, -5, -1, 72, 188);}

    else if(temp>-1&&tempC<0){
	red = map(temp, -1, 0, 188, 255);}

	else if(temp=0){
	red=255;}

	else if(temp>0&&tempC<=1){
	red = map(temp, 0, 1, 255, 184);}

	else if(temp>1&&tempC<=5){
	red = map(temp, 1, 5, 184, 169);}

	else if(temp>5&&tempC<=10){
	red = map(temp, 5, 10, 169, 147);}

	else if(temp>10&&tempC<=15){
	red = map(temp, 10, 15, 147, 255);}

	else if(temp>15&&tempC<=20){
	red = map(temp, 15, 20, 255, 249);}

	else if(temp>20&&tempC<=25){
	red = map(temp, 5, 10, 249, 254);}

	else if(temp>25&&tempC<=30){
	red = map(temp, 10, 15, 254, 255);}

	else if(temp>30&&tempC<=35){
	red = map(temp, 15, 20, 254, 255);}

    else if(temp>35){
    red=254;}

// Bestimmt den Anteil an Gruen

    if(temp<=-20){
    int green=63;}

    else if(temp>-20&&tempC<=-15){
    green = map(temp, -20, -15, 63, 102);}

    else if(temp>-15&&tempC<=-10){
    green = map(temp, -15, -10, 102, 112);}

    else if(temp>-10&&tempC<=-5){
    green = map(temp, -10, -5, 112, 158);}

    else if(temp>-5&&tempC<=-1){
    green = map(temp, -5, -1, 158, 224);}

    else if(temp>-1&&tempC<0){
	green = map(temp, -1, 0, 224, 255);}

	else if(temp=0){
	green=255;}

	else if(temp>0&&tempC<=1){
	green = map(temp, 0, 1, 255, 243);}

	else if(temp>1&&tempC<=5){
	green = map(temp, 1, 5, 243, 205);}

	else if(temp>5&&tempC<=10){
	green = map(temp, 5, 10, 205, 194);}

	else if(temp>10&&tempC<=15){
	green = map(temp, 10, 15, 194, 225);}

	else if(temp>15&&tempC<=20){
	green = map(temp, 15, 20, 225, 132);}

	else if(temp>20&&tempC<=25){
	green = map(temp, 5, 10, 132, 51);}

	else if(temp>25&&tempC<=30){
	green = map(temp, 10, 15, 51, 57);}

	else if(temp>30&&tempC<=35){
	green = map(temp, 15, 20, 57, 140);}

    else if(temp>35){
    green=140;}

// Bestimmt den Anteil an Blau

    if(temp<=-20){
    int blue=244;}

    else if(temp>-20&&tempC<=-15){
    blue = map(temp, -20, -15, 244, 200);}

    else if(temp>-15&&tempC<=-10){
    blue = map(temp, -15, -10, 200, 209);}

    else if(temp>-10&&tempC<=-5){
    blue = map(temp, -10, -5, 209, 231);}

    else if(temp>-5&&tempC<=-1){
    blue = map(temp, -5, -1, 231, 254);}

    else if(temp>-1&&tempC<0){
	blue = map(temp, -1, 0, 254, 255);}

	else if(temp=0){
	blue=255;}

	else if(temp>0&&tempC<=1){
	blue = map(temp, 0, 1, 255, 133);}

	else if(temp>1&&tempC<=5){
	blue = map(temp, 1, 5, 133, 57);}

	else if(temp>5&&tempC<=10){
	blue = map(temp, 5, 10, 57, 0);}

	else if(temp>10&&tempC<=15){
	blue = map(temp, 10, 15, 0, 3);}

	else if(temp>15&&tempC<=20){
	blue = map(temp, 15, 20, 3, 18);}

	else if(temp>20&&tempC<=25){
	blue = map(temp, 5, 10, 18, 47);}

	else if(temp>25&&tempC<=30){
	blue = map(temp, 10, 15, 47, 145);}

	else if(temp>30&&tempC<=35){
	blue = map(temp, 15, 20, 145, 191);}

    else if(temp>35){
    blue=191;}

// Sendet den berechneten RGB-Wert an die jeweilige LED

    pixels.setPixelColor(i, pixels.Color(red,green,blue));
    pixels.show();
    
    delay(30000);
    }
}
