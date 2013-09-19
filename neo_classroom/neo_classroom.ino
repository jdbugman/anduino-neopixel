#include <Adafruit_NeoPixel.h>

#define PIN 5
Adafruit_NeoPixel strip = Adafruit_NeoPixel(212, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int bright = 10;    //select 1 thru 10
int wait = 1;     //select delay on changing from one to another 
int wait2 = 1;     //select speed of flashes in police
int wait3 = .1;     //select speed of color change
int wait4 = .1;       //select speed of larson
int wait5 = 100;    //select duration of light

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
//this is the group of programs for the leds
joker(wait);
larson(wait);
rainbow(wait3);
police(wait2);
roomlight(wait5);

}
  
void joker(int wait) { 
for(int d=0; d< 20 ; d++) {  // how many times it flashe
  for(int i=0; i<strip.numPixels()  ; i++) {
      strip.setPixelColor(i, 0, 150, 50);
      //strip.show();
      delay(wait);
 }
 strip.show();
 for(int i=0; i< strip.numPixels() ; i++) { 
      strip.setPixelColor(i, 150, 0, 100); 
      //strip.show();
      delay(wait);
  }
  strip.show();
  for(int i=0; i< strip.numPixels() ; i++) { 
    strip.setPixelColor(i, 0, 0, 0); 
  }
    //strip.show();
    delay(wait);
}
}

void police(int wait2) { 
for(int d=0; d< 20 ; d++) {  // how many times it flashe
  for(int i=0; i<strip.numPixels()  ; i++) {
      strip.setPixelColor(i, 0, 0, 200);
      //strip.show();
      delay(wait2);
 }
 strip.show();
 for(int i=0; i< strip.numPixels() ; i++) { 
      strip.setPixelColor(i, 200, 0, 0); 
      //strip.show();
      delay(wait2);
  }
  strip.show();
  }
    //strip.show();
    delay(wait2);
}


void race(int wait) { 
  for(int i=0; i< wait ; i++) {
      strip.setPixelColor(0, 100, 100, 100);
      strip.setPixelColor(1, 100, 170, 0);
      strip.setPixelColor(2, 100, 170, 0);
      strip.setPixelColor(3, 100, 100, 100);
      strip.show();
      delay(wait);
  }
}
void roomlight(int wait5) { 
  for(int i=0; i<strip.numPixels() ; i++) {
      strip.setPixelColor(i, 150, 150, 150);
      }
      strip.show();
      delay(wait5);
  }


void rainbow(uint8_t wait3) {
  uint16_t i, j, d;
for(d=0; d < 20; d++){ //this is how many times it will cycle the full rainbow
  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait3);
  }
 }
}
uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
void larson(int wait2) { 
for(int d=0; d< 2 ; d++) {  // how many times it flashe
  for(int i=0; i<strip.numPixels()  ; i++) {
      strip.setPixelColor(i, 255, 0, 0);
      strip.show();
      delay(wait4);
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
      delay(wait4);
  }
  for(int i=2; i<strip.numPixels()  ; i++) {
      strip.setPixelColor(strip.numPixels()-i, 255, 0, 0);
      strip.show();
      delay(wait4);
      strip.setPixelColor(strip.numPixels()-i, 0, 0, 0);
      strip.show();
      delay(wait4);
  }
  }
}



