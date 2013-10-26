#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUM_LED 180
#define SEG_LEN 10

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)

int wait=100; //speed

int num_segments = NUM_LED / SEG_LEN;
int num_colors = 3;
int colors[3][3]; //= (int*)malloc(sizeof(int*num_colors));

int offset = 0;

void setup() {
// Choose colors (be sure you make 
  colors[0][0] = 255; //r (of first color)
  colors[0][1] = 0; //b //orange
  colors[0][2] = 0;   //g

  colors[1][0] = 0;
  colors[1][1] = 255;      //purple
  colors[1][2] = 0;

  colors[2][0] = 0;
  colors[2][1] = 0;      //green
  colors[2][2] = 255;

  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  
  
}
void loop() {
  
  offset = (offset+1)%NUM_LED;
  updateLed(offset,wait);
}

void updateLed(int offset,int wait){
  int i;
  for(i=0; i<num_segments; i++){
    strip.setPixelColor((i*SEG_LEN+offset)%180, 
      strip.Color(colors[i%num_colors][0],
                  colors[i%num_colors][1],
                  colors[i%num_colors][2]));
  }
  strip.show();
  delay(wait);
}



