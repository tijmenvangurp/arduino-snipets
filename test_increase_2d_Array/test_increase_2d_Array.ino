// Test increase 2D array
int test [2][2];
void setup(){
Serial.begin(9600);
}

void loop(){
  test [0][0]--;
  Serial.println(test [0][0]);

}
