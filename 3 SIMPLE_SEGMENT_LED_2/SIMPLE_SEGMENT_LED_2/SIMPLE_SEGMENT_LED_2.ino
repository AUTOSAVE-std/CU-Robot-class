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
  clear();
  digitalWrite(led[0], HIGH);
  digitalWrite(led[9], HIGH);
  delay(100);
  clear();
  digitalWrite(led[1], HIGH);
  digitalWrite(led[8], HIGH);
  delay(100);
  clear();
  digitalWrite(led[2], HIGH);
  digitalWrite(led[7], HIGH);
  delay(100);
  clear();
  digitalWrite(led[3], HIGH);
  digitalWrite(led[6], HIGH);
  delay(100);
  clear();
  digitalWrite(led[4], HIGH);
  digitalWrite(led[5], HIGH);
  delay(100);
  clear();
  digitalWrite(led[3], HIGH);
  digitalWrite(led[6], HIGH);
  delay(100);
  clear();
  digitalWrite(led[2], HIGH);
  digitalWrite(led[7], HIGH);
  delay(100);
  clear();
  digitalWrite(led[1], HIGH);
  digitalWrite(led[8], HIGH);
  delay(100);
  clear();
  digitalWrite(led[0], HIGH);
  digitalWrite(led[9], HIGH);
  
  delay(1000);
  clear();
}
void clear(){
  for(int i=0; i<10; i++){
    digitalWrite(led[i], LOW);
  }  
}
