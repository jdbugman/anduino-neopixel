#include <Adafruit_NeoPixel.h>

#define PIN 5

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(180, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 5); // Red
  colorWipe(strip.Color(255, 127, 0), 5); // Red
  colorWipe(strip.Color(255, 255, 0), 5); // Green
  colorWipe(strip.Color(0, 255, 0), 5); // Green
  colorWipe(strip.Color(0, 0, 255), 5); // Blue
  colorWipe(strip.Color(75, 0, 130), 5); // Red
  colorWipe(strip.Color(143, 0, 255), 5); // Red
  colorWipe(strip.Color(200, 200, 200), 5); // Red
  colorWipe(strip.Color(143, 0, 255), 5); // Red
  colorWipe(strip.Color(75, 0, 130), 5); // Red
  colorWipe(strip.Color(0, 0, 255), 5); // Red
  colorWipe(strip.Color(0, 255, 0), 5); // Red
  colorWipe(strip.Color(255, 255, 0), 5); // Green
  colorWipe(strip.Color(255, 127, 0), 5); // Green
 
 // rainbow(20);
 // rainbowCycle(20);
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      //delay(wait);
  }
}


