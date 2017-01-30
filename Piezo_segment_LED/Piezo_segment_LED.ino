/*
  Piezo

  Piezo with segment LED, recieving signal from analog outout and 
  display on Serial print frmo 9600

  Extra : 10 x 330ohm attached from ground for segment LED
  Extra : 1 x 1M ohm or less for piezo
 
  modified 25 JAN 2016 for CU Robot Class
  by Chawanan Inkumnoi 
  
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ █████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔══██╗██║   ██║██╔════╝
███████║██║   ██║   ██║   ██║   ██║███████╗███████║██║   ██║█████╗  
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║██║  ██║ ╚████╔╝ ███████╗
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝
 
                                                                   
*/

int knockSensor = A0;       // the piezo is connected to analog pin 0
// the value from piezo range from 0 to 1023

const int numReadings = 10;
int readings[numReadings];      // the readings from the analog input
int readIndex = 0;              // the index of the current reading
int total = 0;                  // the running total
int average = 0;                // the average


int finalval = 0;
int sensorReading = 0;      // variable to store the value read from the sensor pin
int led[10] = {2,3,4,5,6,7,8,9,10,11};
void setup() {
  Serial.begin(9600);
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
    readings[thisReading] = 0;
  }
}
void loop() {
  // subtract the last reading:
  total = total - readings[readIndex];
  // read from the sensor:
  readings[readIndex] = analogRead(knockSensor);
  // add the reading to the total:
  total = total + readings[readIndex];
  // advance to the next position in the array:
  readIndex = readIndex + 1;
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  average = total / numReadings;
  Serial.println(average);
  
//  sensorReading = analogRead(knockSensor);
  finalval = map(average, 0, 100, 1, 10);
  displaySegment(finalval);
}
void displaySegment(int finalval) {
  clear();
  for(int i=0; i<finalval; i++){
    digitalWrite(led[i], HIGH);
    
  }
  delay(10);
}
void clear(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }  
}


