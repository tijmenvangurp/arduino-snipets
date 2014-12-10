#include <Adafruit_NeoPixel.h>

#define PIN 6
#define NUMPIXELS 64
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

const byte rows = 16;
const byte collums = 4;
const byte colours_places = 4;
int all_composition [rows][collums];
int collor_settings [rows][colours_places];


int row_counter = 0;
boolean function_1_running = false; 
int brightness_counter = 0;

const byte ammount_of_colours_in_coulors = 3;
int ammount_of_colours_in_coulors_counter = 0;

unsigned long timestamp_function_one = 0;

int colours[ammount_of_colours_in_coulors][colours_places] = {
  {
    255,0,0,100                                                    }
  ,{
    255,255,255,100                                                    }
  ,{
    0,0,255,100                                                    }
};

char state_char = 'B';

void setup(){
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
      // for every row, this loops through all the collums
      all_composition[row_counter][collum_counter]= (row_counter*collums)+collum_counter;
    }
  }

  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    if(ammount_of_colours_in_coulors_counter > ammount_of_colours_in_coulors -1){
      ammount_of_colours_in_coulors_counter = 0;
    }
    for(int collor_setting_counter = 0; collor_setting_counter < colours_places ; collor_setting_counter++){
      // for every row, this loops through all the collums
      // r g b bright langs
      collor_settings[row_counter][collor_setting_counter] = colours[ammount_of_colours_in_coulors_counter][collor_setting_counter];
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
    row_counter = 0; 
  }
  else if(row_counter < rows ){

    int time_passed = micros() - timestamp_function_one;
    if(time_passed > 5000){
      timestamp_function_one = micros();
      brightness_counter++;
      // this loop goes through all the rows
      int r = collor_settings[row_counter][0];
      int g = collor_settings[row_counter][1];
      int b = collor_settings[row_counter][2];

      // if we want to fade we still need this loop to update the setting of the brightness
      // but the brigtness setting needs to be updated over time each loop
      // when we have achieved this go to next row

      for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
        // for every row, this loops through all the collums
        setPixelColor(all_composition[row_counter][collum_counter], r, g, b, brightness_counter);
      }      

      strip.show();
      if(brightness_counter > 100){
        brightness_counter = 0;
        row_counter++;
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
