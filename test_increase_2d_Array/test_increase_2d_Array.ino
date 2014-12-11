// Test increase 2D array
int test [2][2];
void setup(){
  Serial.begin(9600);
}

void loop(){
  test [0][0]--;
  Serial.println(test [0][0]);
  test [0][0]+= 5;
  Serial.println(test [0][0]);
  delay(2000);
  for(int i = 0; i < 5; i++){
    Serial.println(i);
  }
  delay(2000);
  for(int color_settings = 0; color_settings < 4; color_settings++){
    // fill new array with only the colors we want to use
    Serial.print(" current colour = ");
    Serial.print(color_settings);
  }
  delay(2000);

}


