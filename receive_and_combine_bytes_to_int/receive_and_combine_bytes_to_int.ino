
unsigned long time_stamp_receiving = 0; 
unsigned long time_receiving = 0;
void setup(){
  // initialize your serial connection
  Serial.begin(9600); // use the normal serial connection for debugging
  Serial2.begin(9600);// use the second serial connection to send stuff

}

void loop(){

  if (Serial2.available() >= 2){
    // when there are at least 2 bytes ready to recieve recieve them
    // make sure you always send an even number of bytes
    int received_byte = receive_bytes();// this function handles combining the 2 bytes back to an int
    // you can add this int to an array again or do somthing with it
    // for example a switch case
    switch (received_byte){
    case 666:
      {
        Serial.println("start message");
        time_stamp_receiving = micros();
        // you can clear the receiving array here, or set a boolean to true that does something etc
        break;
      }
    case 555:
      {
        time_receiving = micros() - time_stamp_receiving; // we save the time before the serial println's so dont calculate the debugging lines
        Serial.println("end message");
        Serial.print("microseconds it took to receive all bytes" + time_receiving);
        
        break;
      }
    default:
      {
        Serial.println("save value to array or do something else");

        break;
      }


    }
  }


  Serial.println("ready receiving everything");


}

int receive_bytes (){
  int byte_to_read;
  byte_to_read = Serial2.read() << 8 ; // read the least significant byte
  byte_to_read |= Serial2.read(); // add the most significant byte
  return byte_to_read;
}


