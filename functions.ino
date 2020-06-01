
// Functions for the operation of the VFD Futaba M202SD01LJ 


/*Resetting the module.
All the characters displayed are erased, then the write-in position will be set
on the most significant digit of the first row.
The displaying status is the same as the power on reset, and cursor mode is set
for lighting mode, the dimming level is set for 100% */
void VFDreset() 
{
  VFD.write(0x1F);
}

void VFDclear() /*All the characters displayed are erased, the write-in position moves to the most
significant digit of the first row. But the Dimming level and Cursor Mode are kept.*/ 
{
  VFD.write(0x0D); // clear display
}

void VFDdimmer(int amount) // The brightness can be controlled into six levels by using this function.
//After writing 04H, the following dimming data is written to change the rightness output.
{
  VFD.write(0x04);
  VFD.write(amount);
  switch (amount)
  {
  case 20:
    VFD.write(0x04); // clear
    VFD.write(0x20); // 20% Dimmer
    break;
  case 40:
    VFD.write(0x04); // clear
    VFD.write(0x40); // 40% Dimmer
    break;
  case 60:
    VFD.write(0x04); // clear
    VFD.write(0x60); // 60% Dimmer
    break;
  case 80:
    VFD.write(0x04); // clear
    VFD.write(0x80); // 80% Dimmer
    break;
  case 100:
    VFD.write(0x04); // clear
    VFD.write(0xFF); // 100% Dimmer
  }
}

void VFDchars() // The UFO characters run from 21 to 255 described in the datasheet
{
  for (int i = 21; i < 256; i++)
  {
    VFD.write(i);
    delay(30);
  }
}

void setCursor(byte position) /*Instead of writing a character from the first digit, the write-in starting
position can be pointed by using this function.
This function enables move the cursor from 0 to 19 and 20 to 39 in the bottom row*/
{
  VFD.write(0x10);
  VFD.write(position);
}

void VFDbackspace() /*The write-in position is shifted to the left one digit, and the character previously displayed on the digit will be cleared */
{
  VFD.write(0x08);
  }

void VFDhorizontaltab() // The write-in position is shifted to the right one digit.
{
  VFD.write(0x09);
}

void cursormode(int amount) /*The cursor is always displayed at the write-in position.
The cursor is formed by the 5dots located the bottom of 5×7 dot matrix character font.
The cursor will be displayed as an over writing mode and the behavior of the cursor under the lighting mode and blinking mode are explained below.
VFD cursor mode - FF Lighting/  88 Blinking/    00 No Lighting */
{
  VFD.write(0x17);
  VFD.write(amount);
  switch (amount)
  {
  case 255:          
    VFD.write(0x17); 
    VFD.write(0xFF); // Lighting
    break;
  case 88:           
    VFD.write(0x17); 
    VFD.write(0x88); // Blinking
    break;
  }
}

void VFDall() /*The full dots in all digits are displayed.
The dimming level is set for 100%.
To release this mode, the module is turned off or the RST command shall be written*/
{
  VFD.write(0x0F);
}
