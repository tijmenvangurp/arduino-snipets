// Xbee receiving part: only need to check if Serial is available, and print this out to the serial monitor.

// Depending on what we receive we send somerthing else back


char HEADER = 'H';
char LENGTH = 'L';
int length_message = 0;
int byte_to_read;

#include <SoftwareSerial.h>

//Specify the pins to use as serial input/output pin.
//Digital pin 10 is specified as TX (output), and Digital pin 9 is specified as RX (input).
SoftwareSerial xBeeSerial = SoftwareSerial(10, 9);

char c ;

const byte rows = 15;
const byte collums = 5;
int id_array [rows][collums];
int collum_counter = 0;
int row_counter = 0;


void setup(){

  Serial.begin(115200); // hardware serial ( aka computer)
  xBeeSerial.begin(9600); // software serial 
}

void loop(){

  if( xBeeSerial.available() > 3){
    if(xBeeSerial.read() == LENGTH){
      length_message = receive_bytes();
      Serial.print("length message = ");
      Serial.println(length_message);
      Serial.print("Buffer size = ");
      Serial.println(xBeeSerial.available());
    }
  }

  if (length_message != 0 && xBeeSerial.available() == length_message){
    // I have buffered the whole message and can do something with it. 
    row_counter = 0;
    collum_counter = 0;
    for(int i = 0;  i < length_message ; i += 2){
      int received_byte = receive_bytes();

      if(received_byte == 5000){
   //     Serial.println();
        row_counter++;
        collum_counter = 0;
      }
      else{
    //    Serial.print(received_byte);
        id_array [row_counter][collum_counter] = received_byte ;
        collum_counter++;
    //    Serial.print(" ");
      }
    }
  //  Serial.println();
    length_message = 0;
    
    for(int i = 0 ; i < rows ; i++){
      for(int j = 0 ; j < collums ; j++){
        if(id_array[i][j] == 0){
          j = collums;
        }
        else{
          Serial.print(id_array[i][j]);
          Serial.print(" ");
        }
      }
      if(id_array[i][0] == 0){
        Serial.println();
        break;
      }
      else{
        Serial.println();
      }
    }

  }

  memset(id_array, 0, sizeof(id_array[0][0]) * rows * collums);
}

int receive_bytes (){
  byte_to_read = xBeeSerial.read() << 8 ; // read the least significant byte
  byte_to_read |= xBeeSerial.read(); // add the most significant byte
  return byte_to_read;
}


























