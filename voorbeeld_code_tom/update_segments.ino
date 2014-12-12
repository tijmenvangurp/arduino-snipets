void update_per_4 (){

  byte new_order [16] ={
    0,7,8,15,1,6,9,14,2,5,10,13,3,4,11,12  };

  // array to fill current led numbers with appropriate led number per row
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    byte current_order_setting = new_order[row_counter];
    for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
      // for every row, this loops through all the collums

      current_led_numbers[row_counter][collum_counter]= (current_order_setting*collums)+collum_counter;
    }
  }

}

void update_snake (){
  for(int row_counter = 0 ; row_counter < rows ; row_counter++){
    // this loop goes through all the rows
    for(int collum_counter = 0; collum_counter < collums ; collum_counter++){
      // for every row, this loops through all the collums
      current_led_numbers[row_counter][collum_counter]= (row_counter*collums)+collum_counter;
    }
  }

}

