#include <Adafruit_NeoPixel.h>

#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(38, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int bright = 10;    //select 1 thru 10
int wait = 5;    //speed of leds

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
    int randr = random(0,(25*bright));
    int randg = random(0,(25*bright)); 
    int randb = random(0,(25*bright));
    int randi = random(1,strip.numPixels());
    int randii = random(1,strip.numPixels());
    colorWipe(randr, randg, randb, wait);
}   
void colorWipe(int r, int g, int b, int wait) {
  for(int i=0; i<strip.numPixels(); i++) {
    int randr1 = r -(5*bright);
    if (randr1 < 1) randr1 = 5 + bright;
    int randg1 = g -(5*bright); 
    if (randg1 < 1) randg1 = 5 + bright;
    int randb1 = b -(5*bright);
    if (randb1 < 1) randb1 = 5 + bright;
    int randr2 = r -(10*bright);
    if (randr2 < 1) randr2= 2 + bright;
    int randg2 = g -(10*bright); 
    if (randg2 < 1) randg2 = 2 + bright;
    int randb2 = b -(10*bright);
    if (randb2 < 1) randb2 = 2 + bright;
    int randr3 = r -(20*bright);
    if (randr3 < 1) randr3 = 1 + bright;
    int randg3 = g -(20*bright); 
    if (randg3 < 1) randg3 = 1 + bright;
    int randb3 = b -(20*bright);
    if (randb3 < 1) randb3 = 1 + bright;
    strip.setPixelColor(i, r, g, b);
     strip.setPixelColor(i-1, randr1, randg1, randb1);
     strip.setPixelColor(i-2, randr2, randg2, randb2);
     strip.setPixelColor(i-3, randr3, randg3, randb3); // add more of these lines to make the trail longer
      strip.show();
      delay(wait);
      strip.setPixelColor(i-4, strip.Color(0,0,0)); // make sure the i-number is the amount of the trail
      strip.show();
      delay(wait);   
}  
}


