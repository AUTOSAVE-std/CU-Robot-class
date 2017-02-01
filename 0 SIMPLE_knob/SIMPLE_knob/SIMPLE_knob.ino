

int potpin = 1;  // analog pin used to connect the potentiometer 
int val=0;
void setup() {
   Serial.begin(9600);
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  Serial.println(val);                  // print value
  delay(150);
}
