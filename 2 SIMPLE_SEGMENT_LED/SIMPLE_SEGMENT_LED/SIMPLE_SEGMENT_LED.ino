/*
  SIMPLE_SEGMENT_LED

  Simple SEGMENT LED. This program only
  run bar the segment led bar from first to last
  and repeating unstop

  Extra : 10 x 330ohm attached from ground
  
 
  modified 25 JAN 2016 for CU Robot Class
  by Chawanan Inkumnoi 
  
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ █████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔══██╗██║   ██║██╔════╝
███████║██║   ██║   ██║   ██║   ██║███████╗███████║██║   ██║█████╗  
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║██║  ██║ ╚████╔╝ ███████╗
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝
 
                                                                   
*/

int led[10] = {2,3,4,5,6,7,8,9,10,11};
void setup() {
  Serial.begin(9600); 
  for(int i=0; i<10; i++){
    pinMode(led[i], OUTPUT);
  }
}

void loop() {
  for(int i=0; i<10; i++){
    digitalWrite(led[i], HIGH);
    delay(100);
  }
  for(int j=10; j>=0; j--){
    digitalWrite(led[j], LOW);
    Serial.println(j);
    delay(200);
  }
  delay(1000);
}
