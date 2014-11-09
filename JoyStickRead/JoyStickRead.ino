 int ledPin = 13;
 int joyPinX = 0;                 // slider variable connecetd to analog pin 0
 int joyPinY = 1;                 // slider variable connecetd to analog pin 1
 int valueX = 0;                  // variable to read the value from the analog pin 0
 int valueY = 0;                  // variable to read the value from the analog pin 1

 void setup() {
  pinMode(ledPin, OUTPUT);              
  Serial.begin(9600);
 }


 void loop() {
  // reads the value of the variable resistor 
  valueX = analogRead(joyPinX);   
  // this small pause is needed between reading
  // analog pins, otherwise we get the same value twice
  delay(100);             
  // reads the value of the variable resistor 
  valueY = analogRead(joyPinY);   

  digitalWrite(ledPin, HIGH);           
  delay(valueX);
  digitalWrite(ledPin, LOW);
  delay(valueY);

  Serial.print(valueX);
  Serial.print(" , ");
  Serial.println(valueY);
  
  if (valueX > 700 and valueY < 400) {
    Serial.println("upper left!");
  }
  else if (valueX > 700 and valueY < 700) {
    Serial.println("up!");
  }
  else if (valueX > 700 and valueY >= 700) {
    Serial.println("upper right!");
  }
  else if (valueX > 400 and valueY < 400) {
   Serial.println("left!");
  }
  else if (valueX < 400 and valueY < 400) {
   Serial.println("lower left!");
  }
  else if (valueX < 400 and valueY > 700) {
    Serial.println("lower right!");
  }
  else if (valueX < 700 and valueY > 700) {
    Serial.println("right!");
  }
  else if (valueX < 400 and valueY > 400) {
    Serial.println("down!");
  }
  else {
    Serial.println("no movement!");
  }
 }
