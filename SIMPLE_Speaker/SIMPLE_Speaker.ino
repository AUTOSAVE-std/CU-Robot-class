/*
  SIMPLE_SPEAKER

  Simple speaker is a script to output speaker at A2
  using tone https://www.arduino.cc/en/Reference/Tone
 
  modified 25 JAN 2016 for CU Robot Class
  by Chawanan Inkumnoi 
  
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ █████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔══██╗██║   ██║██╔════╝
███████║██║   ██║   ██║   ██║   ██║███████╗███████║██║   ██║█████╗  
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║██║  ██║ ╚████╔╝ ███████╗
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝
 
                                                                   
*/

#define SPEAKER 8
//#define POT_A A0
//#define POT_B A1
//#define POT_C A2
//#define POT_D A3

//int x = 2;
//int osc1 = 0;
//int osc2 = 0;
//int ran = 0;
//int tempo = 0;
//int note;
//bool event = 0;

void setup() {

// Setup all of the DIP Switch pins as Inputs
//for(int i = 0; i<10; i++){
//  pinMode(i, INPUT);
//  digitalWrite(i, 1);
//}


}

void loop() {

 
  tone(SPEAKER, 32767, 200); // Create our tone
  delay(340);
 
  
  tone(SPEAKER, 1661, 100);
  delay(140);
 
  
  tone(SPEAKER, 32767, 300);
  delay(100);
 
  
  tone(SPEAKER, 2794, 510);
  delay(300);
 
  
  tone(SPEAKER, 32767, 200);
  delay(140);
 
  
  tone(SPEAKER, 2093, 440);
  delay(240);
 
  
  tone(SPEAKER, 32767, 400);
  delay(200);
 
  
  tone(SPEAKER, 523, 300);
  delay(340);
 
  
  tone(SPEAKER, 32767, 200);
  delay(140);
 
  
  tone(SPEAKER, 2960, 520);
  noTone(8);
  
  delay(1000);
 
}
