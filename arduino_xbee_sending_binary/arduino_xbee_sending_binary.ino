#include <SoftwareSerial.h>

//Specify the pins to use as serial input/output pin.
//Digital pin 10 is specified as TX (output), and Digital pin 9 is specified as RX (input).
SoftwareSerial xBeeSerial = SoftwareSerial(10, 9);

byte message_to_send [64];
int message_counter = 0;

int message_length;

const char HEADER = 'H';

void setup(){
  Serial.begin(9600);
  xBeeSerial.begin(9600);

}

void loop(){
  // value_to_add(HEADER);

  // message_to_send [message_counter] = HEADER;
  //  xBeeSerial.write(HEADER); // send the header

  prepare_message(100);
  newLine();
  prepare_message(200);
  prepare_message(100);
  newLine();
  prepare_message(200);
  newLine();
  prepare_message(200);

  xBeeSerial.print('L');

  for(int i = 0; i < sizeof(message_to_send); i++ ){
    if(message_to_send[i] == 2){
      message_length = i;
      Serial.println(message_to_send[i]);
      //Serial.println(message_length);
      break;
    }
  }

  xBeeSerial.write(highByte(message_length));
  xBeeSerial.write(lowByte(message_length));


  for(int i = 0; i < message_length; i++ ){
    xBeeSerial.write(message_to_send[i]);
  }

  message_counter = 0;
  memset(message_to_send,2,sizeof(message_to_send));

  delay(1000);

}

void value_to_add(int val){
  message_to_send [message_counter] = val;
  message_counter++;
}

void prepare_message( int value){
  // send the two bytes that comprise an integer
  value_to_add(highByte(value)); // send the high byte
  value_to_add(lowByte(value)); // send the low byte
}

void newLine(){
  prepare_message(5000);

}












