#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 64
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte rows = 16;
const byte collums = 4;
const byte colours_places = 4;
const byte place_red = 0;
const byte place_green = 1;
const byte place_blue = 2;
const byte place_brightnes = 3;

int current_led_numbers [rows][collums];

int new_collour_setting [rows][colours_places];
int current_collour_setting [rows][colours_places];


int row_counter_comp = 0;
boolean updating_leds_per_segment_after_comparing = false; 
updating__all_leds_after_comparing = false;
int brightness_counter = 0;

const byte ammount_of_colours_in_coulors = 4;
int ammount_of_colours_in_coulors_counter = 0;

unsigned long timestamp_function_one = 0;

int colours[ammount_of_colours_in_coulors][colours_places] = {
  {
    255,0,0,100                                                                        }
  ,{
    255,255,255,100                                                                        }
  ,{
    0,0,255,100                                                                        }
  ,{
    0,255,0,100                                                                        }
};

boolean colors_to_use [ammount_of_colours_in_coulors];
const byte bright_red = 0;
const byte green_brightnes_100 = 3;





char state_char = 'S';

void setup(){
  /*
  http://stackoverflow.com/questions/2516096/fastest-way-to-zero-out-a-2d-array-in-c
   memset(array, 0, sizeof(array[0][0]) * m * n);
   Where m and n are the width and height of the two-dimensional array (in your example, you have a square two-dimensional array, so m == n).
   */
  memset(current_collour_setting, 0, sizeof(current_collour_setting[0][0]) * colours_places * rows);


  // array to fill current led numbers with appropriate led number per row
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
      // for every row, this loops through all the collums
      current_led_numbers[row_counter][collum_counter]= (row_counter*collums)+collum_counter;
    }
  }

  // get a collour from the coulors array and fill the current collour setting with these colours
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    if(ammount_of_colours_in_coulors_counter > ammount_of_colours_in_coulors -1){
      ammount_of_colours_in_coulors_counter = 0;
    }
    for(int collor_setting_counter = 0; collor_setting_counter < colours_places ; collor_setting_counter++){
      // for every row, this loops through all the collums
      // r g b bright langs
      new_collour_setting[row_counter][collor_setting_counter] = colours[ammount_of_colours_in_coulors_counter][collor_setting_counter];
    }
    ammount_of_colours_in_coulors_counter++;
  }


  strip.begin();
  // strip.show();
  Serial.begin(9600);
}

void loop (){

  if(Serial.available() > 0 ){// when there is a byte/chareracter avaiable in the buffer Serial.available becomes bigger
    // Serial.available = ammount of bytes in serial buffer
    state_char = Serial.read();
    // Serial.read() gets the byte into the charecter
    switch (state_char){
    case 'A':
      // when in other function first fadeout before fading in
      // fadeout function
      // fadein is standaart
      // TODO: all colors to use to false
      colors_to_use[bright_red] = true; 
      colors_to_use[green_brightnes_100] = true; 
      update_new_colour_setting(0);// fill in brightness setting, if 0 than use brightness of defined colors
      updating_leds_per_segment_after_comparing = true;
      // updating__all_leds_after_comparing = true; 
      break;
    case 'C':
      break;
    case 'O':
      // alles blinken groen
      break;
    default:
      Serial.println("I dont knowt this letter");
      break;
    }
  }

  if(updating_leds_per_segment_after_comparing){
    change_collor_per_segment_to_new_collour();
  }
   if(updating__all_leds_after_comparing){
    change_collor_per_segment_to_new_collour();
  }
}

void setPixelColor( uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint16_t brightness) {
  strip.setPixelColor(n, (brightness*r/255) , (brightness*g/255), (brightness*b/255));
}












