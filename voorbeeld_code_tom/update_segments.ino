void update_per_order (byte new_order_local[]){  

  // array to fill current led numbers with appropriate led number per row
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    byte current_order_setting = new_order_local[row_counter];
    for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
      // for every row, this loops through all the collums

      current_led_numbers[row_counter][collum_counter]= (current_order_setting*collums)+collum_counter;
    }
  }

}


