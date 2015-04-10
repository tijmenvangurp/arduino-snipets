//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 12;
////Pin connected to DS of 74HC595
int dataPin = 11;



void setup(){

  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

  Serial.begin(9600);  
}

void loop(){

   for (int i = 1; i < 256; i= i *2) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    shiftout(0,i);
  }
  for (int i = 1; i < 256; i= i *2) {
    // take the latchPin low so 
    // the LEDs don't change while you're sending in bits:
    shiftout(i,0);
  }



}
void shiftout(int number1, int number2){
  digitalWrite(latchPin, LOW);                     
  shiftOut(dataPin, clockPin, MSBFIRST, number1);    
  shiftOut(dataPin, clockPin, MSBFIRST, number2);   
  digitalWrite(latchPin, HIGH);
  delay(50);
}







