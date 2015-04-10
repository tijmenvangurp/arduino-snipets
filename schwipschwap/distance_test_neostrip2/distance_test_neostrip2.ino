// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include <Adafruit_NeoPixel.h>

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      64

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 50; // delay for half a second

void setup() {
  strip.begin(); // This initializes the NeoPixel library.
  strip.show();
}

void loop (){
  rainbow(20);
  
}
  
  
void rainbow(uint8_t wait) {
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  uint16_t i,j;
  
  for(j=0; j<256; j++) {
    for(i=0;i<strip.numPixels (); i++){
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    strip.setPixelColor(4, Wheel((i+j) & 255));
        delay(wait); // 
    strip.setPixelColor(5, Wheel((i+j) & 255));
        delay(wait); // 
    strip.setPixelColor(6, Wheel((i+j) & 255)); 
        delay(wait); // 
    strip.setPixelColor(7, Wheel((i+j) & 255));
        delay(wait); // 
        
    strip.show(); // This sends the updated pixel color to the hardware.
    delay(wait); // Delay for a period of time (in milliseconds).
      }
  }
}
  
  uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
  } 
  
  


  


