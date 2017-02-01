/*
  knob_speaker_8x8LED

  simply change the sound according to the knob
  and display the level to the led screen
  
  pint D12,D11,D10[DIN,CLK,CS]-8x8LED
  pin A2-knob 
  pin D8-Speaker
 
  modified 25 JAN 2016 for CU Robot Class
  by Chawanan Inkumnoi 
  
 █████╗ ██╗   ██╗████████╗ ██████╗ ███████╗ █████╗ ██╗   ██╗███████╗
██╔══██╗██║   ██║╚══██╔══╝██╔═══██╗██╔════╝██╔══██╗██║   ██║██╔════╝
███████║██║   ██║   ██║   ██║   ██║███████╗███████║██║   ██║█████╗  
██╔══██║██║   ██║   ██║   ██║   ██║╚════██║██╔══██║╚██╗ ██╔╝██╔══╝  
██║  ██║╚██████╔╝   ██║   ╚██████╔╝███████║██║  ██║ ╚████╔╝ ███████╗
╚═╝  ╚═╝ ╚═════╝    ╚═╝    ╚═════╝ ╚══════╝╚═╝  ╚═╝  ╚═══╝  ╚══════╝
 
                                                                   
*/
#include "LedControl.h"
int delayTime=200;
#define SPEAKER 8
#define b0 B00000000;
#define b1 B10000000;
#define b2 B11000000;
#define b3 B11100000;
#define b4 B11110000;
#define b5 B11111000;
#define b6 B11111100;
#define b7 B11111110;
#define b8 B11111111;
int potpin = 1;  // analog pin used to connect the potentiometer 
int val=0;
byte  ledarray[] = {
   B10000000,
   B01000000,
   B00100000,
   B00010000,
   B00001000,
   B00000100,
   B00000010,
   B00000001
};
LedControl lc=LedControl(12,11,10,1); 
void setup() {
   Serial.begin(9600);
   lc.shutdown(0,false); // Wake up displays 0
   lc.setIntensity(0,5); // Set intensity levels, brightness from 0-15
   lc.clearDisplay(0); // Clear Displays
}

void loop() {
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  calculateDisplay(val);
  val = map(val, 0,1023,31,16000);    // map value normalize from 0 -1023 to 31 to 16000
  tone(SPEAKER, val, 5);
  delay(10);
}

void calculateDisplay(int wow)
{
  int me = map(wow, 0,950,0,8);
  byte str;
  for (int i = 0; i < 7; i++)
  {
      ledarray[i] = ledarray[i+1]; 
  }
  if(me==0) ledarray[7] = b0;
  if(me==1) ledarray[7] = b1;
  if(me==2) ledarray[7] = b2;
  if(me==3) ledarray[7] = b3;
  if(me==4) ledarray[7] = b4;
  if(me==5) ledarray[7] = b5;
  if(me==6) ledarray[7] = b6;
  if(me==7) ledarray[7] = b7;
  if(me==8) ledarray[7] = b8;
Serial.println(me);  
  
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,ledarray[i]);
//     Serial.println(me);  
  }
    delay(100);
}

