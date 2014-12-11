void change_collor_per_segment_to_new_collour(){

  if(row_counter_comp < rows ){

    int time_passed = micros() - time_stamp;
    if(time_passed > 100){
      //Serial.println(time_passed);
      time_stamp = micros();
      // this loop goes through all the rows
      int r_new = new_collour_setting[row_counter_comp][place_red];
      int g_new = new_collour_setting[row_counter_comp][place_green];
      int b_new = new_collour_setting[row_counter_comp][place_blue];
      int brightness_new = new_collour_setting[row_counter_comp][place_brightnes];

      int r_current = current_collour_setting[row_counter_comp][place_red];
      int g_current = current_collour_setting[row_counter_comp][place_green];
      int b_current = current_collour_setting[row_counter_comp][place_blue];
      int brightness_current = current_collour_setting[row_counter_comp][place_brightnes];

      compare_old_and_new_coulour_setting(r_current,r_new, place_red);
      compare_old_and_new_coulour_setting(g_current,g_new, place_green);
      compare_old_and_new_coulour_setting(b_current,b_new, place_blue);
      compare_old_and_new_coulour_setting(brightness_current, brightness_new, place_brightnes);

      // the brightness, r, g and b should change to the new setting
      // so we must now what the color setting of the composition was, and what it should be
      // for example if the current Red value in the all composition array is smaller than the new vallue, we must increase R untill it is the same as the new vallue
      // same counts for G B and Brightness
      // But when the old value of R is bigger than the new value we must decrease its value untill it is the same as the new vallue

      for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
        // for every row, this loops through all the collums
        setPixelColor(current_led_numbers[row_counter_comp][collum_counter], r_current, g_current, b_current, brightness_current);
      }      
      strip.show();
      if(r_new == r_current && g_new == g_current && b_new == b_current && brightness_current == brightness_new){
        // done with changing colours update the next compartment
//        Serial.print("current row = ");
//        Serial.print(row_counter_comp);
//        Serial.print(" r= ");
//        Serial.print(r_current);
//        Serial.print(" g= ");
//        Serial.print(g_current);
//        Serial.print(" b= ");
//        Serial.print(b_current);
//        Serial.print(" br= ");
//        Serial.println(brightness_current);
        row_counter_comp++;
      }
    }

  }
  else{
    // reset function
    Serial.println("finished setting new color");

    row_counter_comp = 0; 
    updating_leds_per_segment_after_comparing = false;
  }
}


void compare_old_and_new_coulour_setting (int current_coulour, int new_collour, int current_color_place){

//  if(current_coulour > 255 || current_coulour < 0 || new_collour > 255 || new_collour < 0 ){
//    switch (current_color_place){
//    case 0:
//      Serial.println("red");
//      break;
//    case 1:
//      Serial.println("green");
//      break;
//    case 2:
//      Serial.println("blue");
//      break;
//    case 3:
//      Serial.println("brightness");
//      break;
//    default:
//      Serial.println("error unknown colorsetting");
//
//    } 
//    Serial.println("Something went wrong in comparing values");
//    Serial.print("current_coulour = "); 
//    Serial.print(current_coulour);
//    Serial.print(" new_collour = ");
//    Serial.println(new_collour);  
//  }

//    Serial.print("current_coulour = "); 
//    Serial.print(current_coulour);
//    Serial.print(" new_collour = ");
//    Serial.println(new_collour);  
  if(current_coulour > new_collour){
    // current_coulour must become biger
    int value_to_add = current_collour_setting[row_counter_comp][current_color_place] -1; 
    current_collour_setting[row_counter_comp][current_color_place] = value_to_add ;
  }
  else if(current_coulour < new_collour){
    // current_coulour must become smaller
    
    int value_to_add = current_collour_setting[row_counter_comp][current_color_place] +1; 
    
//    switch (current_color_place){
//    case 0:
//      Serial.println("red");
//      break;
//    case 1:
//      Serial.println("green");
//      break;
//    case 2:
//      Serial.println("blue");
//      break;
//    case 3:
//      Serial.println("brightness");
//      break;
//    default:
//      Serial.println("error unknown colorsetting");
//    } 
//    Serial.print(" Old ");
//    Serial.print(current_collour_setting[row_counter_comp][current_color_place]);
    current_collour_setting[row_counter_comp][current_color_place]  = value_to_add;
//    Serial.print(" New ");
//    Serial.println(current_collour_setting[row_counter_comp][current_color_place]);
  }

}






