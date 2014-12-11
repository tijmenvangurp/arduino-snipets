void change_all_to_color(){

  int time_passed = micros() - time_stamp;
  if(time_passed > 50000){
    time_stamp = micros();

    // this loop goes through all the rows
    int counter_amount_of_colours_to_update = 0;
    for(int row_counter = 0 ; row_counter < rows ; row_counter++){
      if( finished_updating_this_segment[row_counter] == false){

        counter_amount_of_colours_to_update ++;

        int r_new = new_collour_setting[row_counter][place_red];
        int g_new = new_collour_setting[row_counter][place_green];
        int b_new = new_collour_setting[row_counter][place_blue];
        int brightness_new = new_collour_setting[row_counter_comp][place_brightnes];

        int r_current = current_collour_setting[row_counter][place_red];
        int g_current = current_collour_setting[row_counter][place_green];
        int b_current = current_collour_setting[row_counter][place_blue];
        int brightness_current = current_collour_setting[row_counter][place_brightnes];

        if(r_current =! r_new){
          Serial.println(row_counter);
          Serial.println("r_c was not r_n");
        }
        else{
          Serial.println("r_c was r_n");
        }

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
          setPixelColor(current_led_numbers[row_counter][collum_counter], r_current, g_current, b_current, brightness_current);
        }        
        if(r_new == r_current && g_new == g_current && b_new == b_current && brightness_current == brightness_new){
          // done with changing colours update the next compartment
          finished_updating_this_segment[row_counter] == true;
          // Serial.print("Finished with row ");
          //  Serial.println(row_counter);
          // boolean to check if done
        }
      }
    }

    if(counter_amount_of_colours_to_update == 0){
      Serial.println("done updating all colours at once");
      updating__all_leds_after_comparing = false;
      for(int i = 0; i < rows ; i++){
        finished_updating_this_segment[i] = false;
      }
    }
    // end for loop
    strip.show();
  }
}











