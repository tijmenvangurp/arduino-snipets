#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 64
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte rows = 16;
const byte collums = 4;
const byte colours_places = 4;
int current_led_numbers [rows][collums];

int new_collour_setting [rows][colours_places];
int current_collour_setting [rows][colours_places];


int row_counter_function_one = 0;
boolean function_1_running = false; 
int brightness_counter = 0;

const byte ammount_of_colours_in_coulors = 3;
int ammount_of_colours_in_coulors_counter = 0;

unsigned long timestamp_function_one = 0;

int colours[ammount_of_colours_in_coulors][colours_places] = {
  {
    255,0,0,100                                                            }
  ,{
    255,255,255,100                                                            }
  ,{
    0,0,255,100                                                            }
};

char state_char = 'B';

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
  }

  if(state_char != 'B'){
    switch (state_char){
    case 'A':
      // when in other function first fadeout before fading in
      // fadeout function
      // fadein is standaart
      function_1();
      state_char = 'B';
      break;
    case 'C':
      function_1();
      break;
    case 'O':
      // alles blinken groen
      break;
    default:
      Serial.println("I dont knowt this letter");
      break;
    }
  }
}

void function_1(){

  if(function_1_running == false){
    function_1_running = true; 
    row_counter_function_one = 0; 
  }
  else if(row_counter_function_one < rows ){

    int time_passed = micros() - timestamp_function_one;
    if(time_passed > 5000){
      timestamp_function_one = micros();

      brightness_counter++;
      // this loop goes through all the rows

      int r_new = new_collour_setting[row_counter_function_one][0];
      int g_new = new_collour_setting[row_counter_function_one][1];
      int b_new = new_collour_setting[row_counter_function_one][2];
      int brightness_new = new_collour_setting[row_counter_function_one][3];

      int r_current = current_collour_setting[row_counter_function_one][0];
      int g_current = current_collour_setting[row_counter_function_one][1];
      int b_current = current_collour_setting[row_counter_function_one][2];
      int brightness_current = current_collour_setting[row_counter_function_one][3];

      if(r_new > r_current){
        // r must becomes 

      }
      else if(r_new < r_current){
        // r must become bigger

      }
      else if(r_new == r_current){
        // old becomes current? dunno?      


      }


      // the brightness, r, g and b should change to the new setting
      // so we must now what the color setting of the composition was, and what it should be
      // for example if the current Red value in the all composition array is smaller than the new vallue, we must increase R untill it is the same as the new vallue
      // same counts for G B and Brightness
      // But when the old value of R is bigger than the new value we must decrease its value untill it is the same as the new vallue


      for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
        // for every row, this loops through all the collums
        setPixelColor(current_led_numbers[row_counter_function_one][collum_counter], r_current, g_current, b_current, brightness_current);
      }      

      strip.show();
      if(brightness_counter > 100){
        brightness_counter = 0;
        row_counter_function_one++;
      }
    }
    //    Serial.print("The time pased = ");
    //    Serial.print(time_passed):
    //    Serial.println(" milliseconds");
  }
}

void setPixelColor( uint16_t n, uint8_t r, uint8_t g, uint8_t b, uint16_t brightness) {
  strip.setPixelColor(n, (brightness*r/255) , (brightness*g/255), (brightness*b/255));
}




