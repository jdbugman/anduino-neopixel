#include <Adafruit_NeoPixel.h>

#define PIN 5

Adafruit_NeoPixel strip = Adafruit_NeoPixel(185, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
  int p=0;
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
     int randr = random(0,20);
     int randb = random(0,20);
     strip.setPixelColor(i, strip.Color(255,0,0));
     strip.setPixelColor(i+50, strip.Color(0,255,0));
     strip.setPixelColor((180-(i)), strip.Color(0,0,255));
      strip.show();
      delay(wait);
     strip.setPixelColor(i+45, strip.Color(0,0,0));
     strip.setPixelColor((i-5), strip.Color(0,0,0)); // make sure the i-number is the amount of the trail
     strip.setPixelColor((180-(i-5)), strip.Color(0,0,0)); 
      strip.show();
      delay(wait);  
  }
}


