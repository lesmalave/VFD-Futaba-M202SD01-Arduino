
#ifndef VFDUART_H_INCLUDED
#define VFDUART_H_INCLUDED

#include <SoftwareSerial.h>
SoftwareSerial vfd(2, 3); // (rx, tx) Only connect the TX pin of the arduino to the RX pin of the display

// Functions for the operation of the vfd Futaba M202SD01LJ 

/*Resetting the module.
All the characters displayed are erased, then the write-in position will be set
on the most significant digit of the first row.
The displaying status is the same as the power on reset, and cursor mode is set
for lighting mode, the dimming level is set for 100% */
void vfdreset() 
{
  vfd.write(0x1F);
}

void vfdclear() /*All the characters displayed are erased, the write-in position moves to the most
significant digit of the first row. But the Dimming level and Cursor Mode are kept.*/ 
{
  vfd.write(0x0D); // clear display
}

void vfddimmer(int amount) // The brightness can be controlled into six levels by using this function.
//After writing 04H, the following dimming data is written to change the rightness output.
{
  vfd.write(0x04);
  vfd.write(amount);
  switch (amount)
  {
  case 20:
    vfd.write(0x04); // clear
    vfd.write(0x20); // 20% Dimmer
    break;
  case 40:
    vfd.write(0x04); // clear
    vfd.write(0x40); // 40% Dimmer
    break;
  case 60:
    vfd.write(0x04); // clear
    vfd.write(0x60); // 60% Dimmer
    break;
  case 80:
    vfd.write(0x04); // clear
    vfd.write(0x80); // 80% Dimmer
    break;
  case 100:
    vfd.write(0x04); // clear
    vfd.write(0xFF); // 100% Dimmer
  }
}

void vfdchars() // The UFO characters run from 21 to 255 described in the datasheet
{
  for (int i = 21; i < 256; i++)
  {
    vfd.write(i);
    delay(30);
  }
}

void setCursor(byte position) /*Instead of writing a character from the first digit, the write-in starting
position can be pointed by using this function.
This function enables move the cursor from 0 to 19 and 20 to 39 in the bottom row*/
{
  vfd.write(0x10);
  vfd.write(position);
}

void vfdbackspace() /*The write-in position is shifted to the left one digit, and the character previously displayed on the digit will be cleared */
{
  vfd.write(0x08);
  }

void vfdhorizontaltab() // The write-in position is shifted to the right one digit.
{
  vfd.write(0x09);
}

void cursormode(int amount) /*The cursor is always displayed at the write-in position.
The cursor is formed by the 5dots located the bottom of 5×7 dot matrix character font.
The cursor will be displayed as an over writing mode and the behavior of the cursor under the lighting mode and blinking mode are explained below.
vfd cursor mode - FF Lighting/  88 Blinking/    00 No Lighting */
{
  vfd.write(0x17);
  vfd.write(amount);
  switch (amount)
  {
  case 255:          
    vfd.write(0x17); 
    vfd.write(0xFF); // Lighting
    break;
  case 88:           
    vfd.write(0x17); 
    vfd.write(0x88); // Blinking
    break;
  }
}

void vfdall() /*The full dots in all digits are displayed.
The dimming level is set for 100%.
To release this mode, the module is turned off or the RST command shall be written*/
{
  vfd.write(0x0F);
}

#endif