#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
   colorWipe (0, 0, 255, 50); // the 4th number controls the speed
}
void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, strip.Color(r,g,b));
      strip.setPixelColor(i-1, strip.Color(r,g,(b-150)));
      strip.setPixelColor(i-2, strip.Color(r,g,(b-200)));
      strip.setPixelColor(i-3, strip.Color(r,g,(b-250))); // add more of these lines to make the trail longer
      strip.show();
      delay(wait);
      strip.setPixelColor(i-4, strip.Color(r,g,0)); // make sure the i-number is the amount of the trail
      strip.show();
      delay(wait);  
  }
}


