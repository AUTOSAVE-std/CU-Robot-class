/*
  Piezo

  Simple Piezo, recieving signal from analog outout and 
  display on Serial print from 9600
  
  Extra : 1 x 1M ohm or less
  
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
int sensorReading = 0;      // variable to store the value read from the sensor pin
void setup() {
  Serial.begin(9600);
}
void loop() {
  sensorReading = analogRead(knockSensor);
  Serial.println(sensorReading);
}
