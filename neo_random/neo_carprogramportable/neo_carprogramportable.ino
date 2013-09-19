#include <Adafruit_NeoPixel.h>

#define PIN 6
Adafruit_NeoPixel strip = Adafruit_NeoPixel(7, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int bright = 9;    //select 1 thru 10
int wait = 110;     //select delay on changing from one to another 
int wait2 = 100;     //select speed of flashes in police
int wait3 = 10;     //select speed of color change
int wait4 = 50;       //select speed of larson

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}
void loop() {
//this is the group of programs for the leds
joker(wait);
race(wait);
evil(wait);
larson(wait);
rainbow(wait2);
police(wait2);
caution(wait);
strobe(wait);
}
  
void joker(int wait) { 
 for(int i=0; i< wait ; i++) {
      strip.setPixelColor(0, 0, 250, 50);
      strip.setPixelColor(1, 250, 0, 100);
      strip.setPixelColor(2, 250, 0, 100);
      strip.setPixelColor(3, 0, 250, 50);
      strip.show();
      delay(100);
  }
}
  
void police(int wait2) { 

  for(int d=0; d< 20 ; d++) {  // how many times it flashe
      strip.setPixelColor(0, 0, 0, 255);
      strip.setPixelColor(1, 255, 0, 0);
      strip.setPixelColor(2, 255, 0, 0);
      strip.setPixelColor(3, 0, 0, 255);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 255, 0, 0);
      strip.setPixelColor(1, 0, 0, 255);
      strip.setPixelColor(2, 0, 0, 255);
      strip.setPixelColor(3, 255, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 255, 255, 255);
      strip.setPixelColor(1, 255, 255, 255);
      strip.setPixelColor(2, 255, 255, 255);
      strip.setPixelColor(3, 255, 255, 255);
      strip.show();
      delay(wait2);
  }
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
void evil(int wait) { 
  for(int i=0; i< wait ; i++) {
      strip.setPixelColor(0, 250, 0, 0);
      strip.setPixelColor(1, 250, 0, 0);
      strip.setPixelColor(2, 250, 0, 0);
      strip.setPixelColor(3, 250, 0, 0);
      strip.show();
      delay(wait);
  }
}
void rainbow(uint8_t wait) {
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
for(int d=0; d< 20 ; d++) {  // how many times it flashe
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
void caution(int wait2) { 

  for(int d=0; d< 20 ; d++) {  // how many times it flashes
      strip.setPixelColor(0, 255, 255, 0);
      strip.setPixelColor(1, 255, 255, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 255, 255, 0);
      strip.setPixelColor(3, 255, 255, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
  }
}
void strobe(int wait2) { 

  for(int d=0; d< 20 ; d++) {  // how many times it flashe
      strip.setPixelColor(0, 255, 255, 255);
      strip.setPixelColor(1, 255, 255, 255);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 255, 255, 255);
      strip.setPixelColor(1, 255, 255, 255);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 255, 255, 255);
      strip.setPixelColor(1, 255, 255, 255);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 255, 255, 255);
      strip.setPixelColor(3, 255, 255, 255);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 255, 255, 255);
      strip.setPixelColor(3, 255, 255, 255);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 255, 255, 255);
      strip.setPixelColor(3, 255, 255, 255);
      strip.show();
      delay(wait2);
      strip.setPixelColor(0, 0, 0, 0);
      strip.setPixelColor(1, 0, 0, 0);
      strip.setPixelColor(2, 0, 0, 0);
      strip.setPixelColor(3, 0, 0, 0);
      strip.show();
      delay(wait2);
  }
}


