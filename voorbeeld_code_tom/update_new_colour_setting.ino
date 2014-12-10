void update_new_colour_setting( int brightness_setting){

  // check amount of colors
  int current_colors[10][4];
  int ammount_of_colors = 0;
  int place_counter_current_colors = 0;




  if(brightness_setting != 0){
    for(int current_row = 0; current_row < rows ; current_row++){
      if(colors_to_use[current_row]){
        for(int color_settings; color_settings < 3; color_settings++){
          // fill new array with only the colors we want to use
          current_colors[ammount_of_colors][color_settings] = colours[current_row][color_settings];
        }
        current_colors[ammount_of_colors][3] = brightness_setting;
        ammount_of_colors++;
      }
    }
  }
  else{
    for(int current_row = 0; current_row < rows ; current_row++){
      if(colors_to_use[current_row]){
        for(int color_settings; color_settings < 4; color_settings++){
          // fill new array with only the colors we want to use
          current_colors[ammount_of_colors][color_settings] = colours[current_row][color_settings];
        }
        ammount_of_colors++;
      }
    }
  }

  if(ammount_of_colors > 1){
    // more than one color

    for(int row_counter = 0 ; row_counter < rows ; row_counter++){
      // this loop goes through all the rows

      if(place_counter_current_colors > ammount_of_colors){
        ammount_of_colours_in_coulors_counter = 0;
      }    

      for(int collor_setting_counter = 0; collor_setting_counter < colours_places ; collor_setting_counter++){
        // for every row, this loops through all the collums
        // r g b bright langs
        new_collour_setting[row_counter][collor_setting_counter] = current_colors[place_counter_current_colors][collor_setting_counter];
      }
      place_counter_current_colors++;
    }


  }
  else if (ammount_of_colors == 1){
    // there was only one color 

    for(int row_counter = 0 ; row_counter < rows ; row_counter++){
      // this loop goes through all the rows

      for(int collor_setting_counter = 0; collor_setting_counter < colours_places ; collor_setting_counter++){
        // for every row, this loops through all the collums
        // r g b bright langs
        new_collour_setting[row_counter][collor_setting_counter] = current_colors[0][collor_setting_counter];
      }
    }



  }
  else{
    // no colors
    Serial.println("No colors dude!");
    memset(current_collour_setting, 0, sizeof(current_collour_setting[0][0]) * colours_places * rows);
  }
 
}






