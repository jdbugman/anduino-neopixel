#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
  int p=2;
  colorWipe(255, 0, 0, p); // Red
  colorWipe(255, 127, 0, p); // Red
  colorWipe(255, 255, 0, p); // Green
  colorWipe(0, 255, 0, p); // Green
  colorWipe(0, 0, 255, p); // Blue
  colorWipe(75, 0, 130, p); // Red
  colorWipe(255, 255, 255, p); // Red
  colorWipe(75, 0, 130, p); // Red
  colorWipe(0, 0, 255, p); // Red
  colorWipe(0, 255, 0, p); // Red
  colorWipe(255, 255, 0, p); // Green
  colorWipe(255, 127, 0, p); // Green // the 4th number controls the speed
}
void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(r,g,b));
      strip.show();
      delay(wait);
     //strip.setPixelColor(i, strip.Color(0,0,0)); // make sure the i-number is the amount of the trail
      strip.show();
      delay(wait);  
  }
}


