/*
  knob_segment

  ratate servo via knob
  
  pin A2-knob
  pin {2,3,4,5,6,7,8,9,10,11} -segment 
 
  modified 25 JAN 2016 for CU Robot Class
  by Chawanan Inkumnoi 
  
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ █████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔══██╗██║   ██║██╔════╝
███████║██║   ██║   ██║   ██║   ██║███████╗███████║██║   ██║█████╗  
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║██║  ██║ ╚████╔╝ ███████╗
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝
 
                                                                   
*/
 
 
int led[10] = {3,4,5,6,7,8,9,10,11,12};
int potpin = 2;  // analog pin used to connect the potentiometer 
int val = 0;

 
void setup() {
    Serial.begin(9600);

    for(int i=0; i<10; i++){
      pinMode(led[i], OUTPUT);
    }
}

void loop() {
  for(int j=10; j>=0; j--){
    digitalWrite(led[j], LOW);

  }
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map (val, 0,1023, 0,10);
      Serial.println(val);
  for(int i=0; i<val; i++){
    digitalWrite(led[i], HIGH);
 
  }
  delay(10);
}
 

