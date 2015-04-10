#define trigPin 12
#define echoPin 9


int outputValue;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(6, OUTPUT);
  
}

void loop() {
  int duration, distance;
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
//  if (distance >= 255 || distance <= 0){
//    Serial.println("Out of range");
//  }
//  else {
    Serial.print(distance);
    Serial.print(" cm              ");
    
    outputValue = map (distance, 0, 66, 255, 0);
    
    Serial.println(outputValue);
    
    analogWrite(6, outputValue); 
 
delay(20);
  
}
