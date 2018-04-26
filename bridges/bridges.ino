#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif
#define PIN            6
#define NUMPIXELS      64
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  pixels.begin();
  Serial.begin(9600);  
}


String inString;
String subInstring;

void loop() {
   if (Serial.available() > 0) {
      inString = Serial.readStriGng();
      Serial.print(inString);
      for(int i=0;i<NUMPIXELS;i++){
        subInstring=inString.substring(i,i+1);
        Serial.print(subInstring);
        switch (subInstring[0]) {
          case 'R':
            pixels.setPixelColor(i, pixels.Color(200,0,0));
            break;
           case 'G':
            pixels.setPixelColor(i, pixels.Color(0,200,0));
            break;
           case 'B':
            pixels.setPixelColor(i, pixels.Color(0,0,200));
            break;
           case 'Y':
            pixels.setPixelColor(i, pixels.Color(255,255,000));
            break;
           case 'O':
            pixels.setPixelColor(i, pixels.Color(255,117,20));
            break;
           case 'W':
            pixels.setPixelColor(i, pixels.Color(10,10,10));
            break;
           case 'P':
            pixels.setPixelColor(i, pixels.Color(128,0,128));
            break;
           case 'N':
            pixels.setPixelColor(i, pixels.Color(0,0,0));
            break;
          }
         pixels.show();
        }
    }       
 }

