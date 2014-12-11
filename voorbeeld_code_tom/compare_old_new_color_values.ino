void compare_old_and_new_coulour_setting (byte current_coulour, byte new_collour, byte current_color_place ){

  if(current_coulour > new_collour){
    // current_coulour must become smaller     
    current_collour_setting[row_counter_comp][current_color_place] -- ;
  }
  else if(current_coulour < new_collour){
    // current_coulour must become bigerer 
    current_collour_setting[row_counter_comp][current_color_place]++;

  }

}

