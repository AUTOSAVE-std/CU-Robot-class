/*
  SIMPLE_8x8LED

  This is a simple 8x8 LED prgram that display
  a loop animation
 
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

LedControl lc=LedControl(12,11,10,3);  // Pins: DIN,CLK,CS, # of Display connected

unsigned long delayTime=200;  // Delay between Frames

// Put values in arrays
byte invader1a[] =
{
   B00000000,  // First frame of invader #1
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
};

void setup()
{
  lc.shutdown(0,false);  // Wake up displays 0,1,2
  lc.shutdown(1,false);
  lc.shutdown(2,false);
  
  lc.setIntensity(0,15);  // Set intensity levels, brightness from 0-15
  lc.setIntensity(1,15);
  lc.setIntensity(2,15);
  
  lc.clearDisplay(0);  // Clear Displays
  lc.clearDisplay(1);
  lc.clearDisplay(2);
}


//  Take values in Arrays and Display them
void sinvader1a()
{
  for (int i = 0; i < 8; i++)  
  {
    lc.setRow(0,i,invader1a[i]);
  }
}

void sinvader1b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader1b[i]);
  }
}

void sinvader2a()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader2a[i]);
  }
}

void sinvader2b()
{
  for (int i = 0; i < 8; i++)
  {
    lc.setRow(0,i,invader2b[i]);
  }
}


void loop()
{
// Put #1 frame on  Display
    sinvader1a();
    delay(delayTime);
// Put #2 frame on  Display
    sinvader1b();
    delay(delayTime*3);
// Put #3 frame on  Display
    sinvader2a();
    delay(delayTime);
// Put #4 frame on  Display
    sinvader2b();
    delay(delayTime*3);
}
