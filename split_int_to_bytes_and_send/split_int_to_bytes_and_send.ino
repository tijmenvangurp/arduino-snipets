byte values_to_send [64]; // <<-- max 64 bytes long serial buffer is not any bigger, 
//if you need to send more send it in batches or be sure that the other arduino does a serial read before the whole
// message is received
int array_counter = 0; // the array counter is reset to 0 once we construct a new message

void setup(){
  // initialize your serial connection
  Serial.begin(9600); // use the normal serial connection for debugging
  Serial2.begin(9600);// use the second serial connection to send stuff
}

void loop(){
  
  array_counter = 0; // don't forget to reset the array counter somewhere in your code
  memset(values_to_send,0,sizeof(values_to_send)); // memset is a c++ function that lets you set all values of an array to a given number this case 0
  prepare_message(666);// start message so that the receiving part knows it has the start of a message
  prepare_message(5000);// this line will call upon the prepare message function and pass the int value,
  // the function will handle the splitting into 2 byte values and adding it to the array to send. 
  prepare_message(200);// each time you want to send a new number use this function
  prepare_message(555);// end message; lets say you always add a certain number as the end of the message this case you know when you have received everything
  
  // the only thing that lasts is sending it
  for(int i = 0; i < sizeof(values_to_send); i++{
    Serial2.write(values_to_send[i]);
  
  }
   if(potmeter_values_to_send[i] == lowByte(555)){
          break;// break will stop the for loop
          // if we have the last byte we can stop sending, the array of bytes is filled with 0 after 5000
        }

}

s
void prepare_message( int value){
  // send the two bytes that comprise an integer
  value_to_add(highByte(value)); // send the high byte
  value_to_add(lowByte(value)); // send the low byte
}

void value_to_add(byte value){
  /*
  This functoin adds the high or low significant byte of the prepare message function
   */
  values_to_send [array_counter] = value;
  array_counter++;
}
