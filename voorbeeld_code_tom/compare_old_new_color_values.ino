void compare_old_and_new_coulour_setting (byte current_coulour, byte new_collour, byte current_color_place){

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
     
    current_collour_setting[row_counter_comp][current_color_place] -- ;
  }
  else if(current_coulour < new_collour){
    // current_coulour must become smaller   
   
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
//   Serial.print(current_collour_setting[row_counter_comp][current_color_place]);
    current_collour_setting[row_counter_comp][current_color_place]++;
//   Serial.print(" New ");
//    Serial.println(current_collour_setting[row_counter_comp][current_color_place]);
  }

}
