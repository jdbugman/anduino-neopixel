#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(32, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int bright = 10;    //select 1 thru 10
int wait = 10;    //speed of leds


void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
    
 
void colorWipe(int r, int g, int b, int wait); {
  for(int i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
    //strip.setPixelColor(32-i, strip.Color(255, 0, 0));
    strip.show();
    delay(wait);
    strip.setPixelColor(i-5, strip.Color(0,0,0));
    //strip.setPixelColor(32-i, strip.Color(0,0,0));
    strip.show();
    delay(wait);   
    
  }    
void colorWipe(int r, int g, int b, int wait); {
  for(int i=0; i<strip.numPixels(); i++) {
    //strip.setPixelColor(i, strip.Color(255, 0, 0));
    strip.setPixelColor(32-i, strip.Color(255, 0, 0));
    strip.show();
    delay(wait);
    //strip.setPixelColor(i, strip.Color(0,0,0));
    strip.setPixelColor(37-i, strip.Color(0,0,0));
    strip.show();
    delay(wait);       
}  
}

}
}
