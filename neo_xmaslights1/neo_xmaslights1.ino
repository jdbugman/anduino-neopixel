#include <Adafruit_NeoPixel.h>

#define PIN 5
#define NUM_LED 180
#define SEG_LEN 1

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LED, PIN, NEO_GRB + NEO_KHZ800); //first number controls the amount of pixels you have (add 4 so the drip falls off the edge)
int wait= 100;    //speed of flashing

int num_segments = NUM_LED / SEG_LEN;
int num_colors = 5;
int colors[5][3]; //= (int*)malloc(sizeof(int*num_colors));

int offset = 0;

void setup() {
// Choose colors (be sure you make 
  colors[0][0] = 200; //r (of first color)
  colors[0][1] = 20;  //g //orange
  colors[0][2] = 0;  //b

  colors[1][0] = 0;
  colors[1][1] = 20;     
  colors[1][2] = 200;

  colors[2][0] = 0;
  colors[2][1] = 200;      //green
  colors[2][2] = 20;
  
  colors[3][0] = 0;
  colors[3][1] = 175;      //green
  colors[3][2] = 200;
  
  colors[4][0] = 100;
  colors[4][1] = 100;      //green
  colors[4][2] = 100;
  
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



