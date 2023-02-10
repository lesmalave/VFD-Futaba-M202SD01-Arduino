// Code worked for vfd Futaba M202SD01LJ
// Luis Malavé 2018 @lesmalave @e_smartlabs (twitter & Instagram)
// luisbmalave@gmail.com

#include "VfdUart.h""


void setup()
{
  vfd.begin(9600); // Serial port is set to 9600 bauds supported by vfd
  vfdreset();
  vfdclear();
}

void loop()
{
  setCursor(3);   // 4 position on vfd
  cursormode(88); // Cursor mode BLINKING
  delay(4000);
  // cursormode(0);
  vfdhorizontaltab();
  setCursor(4);
  vfd.write("W");
  delay(200);
  vfd.write("e");
  delay(200);
  vfd.write("l");
  delay(200);
  vfd.write("c");
  delay(200);
  vfd.write("o");
  delay(200);
  vfd.write("m");
  delay(200);
  vfd.write("e");
  delay(300);
  vfd.write(" ");
  delay(200);
  vfd.write("t");
  delay(200);
  vfd.write("o");
  delay(200);
  vfd.write(" ");
  delay(200);
  setCursor(23); // 2nd line
  vfd.write("e");
  delay(200);
  vfd.write(" ");
  delay(200);
  vfd.write("S");
  delay(200);
  vfd.write("m");
  delay(200);
  vfd.write("a");
  delay(200);
  vfd.write("r");
  delay(200);
  vfd.write("t");
  delay(200);
  vfd.write(" ");
  delay(200);
  vfd.write("L");
  delay(200);
  vfd.write("a");
  delay(200);
  vfd.write("b");
  delay(200);
  vfd.write("s");
  delay(2000);

  cursormode(255); // Cursor mode LIGHT

  for (int positionCounter = 0; positionCounter < 40; positionCounter++)
  {
    vfdbackspace(); // Clear the display to the left counting from position 40 to position 0
    delay(50);
  }
  cursormode(0); // Cursor mode NO LIGHT

  vfdclear();

  setCursor(1); // 1st line
  vfd.print("Using vfd Serial");
  setCursor(21); // 2nd line
  vfd.print("FUTABA M202SD01LJ");
  delay(2000);
  vfdclear();
  setCursor(1);
  vfd.print("    Now a sample ");
  setCursor(20);
  vfd.print("    Dimmer control ");

  for (int i = 0; i < 3; i++)
  { // Turn the display on and off 3 times (function "for")
    vfddimmer(0);
    delay(250);
    vfddimmer(255);
    delay(800);
  }
  delay(2000);
  vfdclear();
  vfddimmer(20); // dimmer 20%
  setCursor(4);
  vfd.print("20% Dimmer");
  delay(500);
  vfdclear();
  vfddimmer(40);
  setCursor(4);
  vfd.print("40% Dimmer");
  delay(500);
  vfdclear();
  vfddimmer(60);
  setCursor(4);
  vfd.print("60% Dimmer");
  delay(500);
  vfdclear();
  vfddimmer(80);
  setCursor(4);
  vfd.print("80% Dimmer");
  delay(500);
  vfdclear();
  setCursor(4);
  vfddimmer(100);
  vfd.print("100% Dimmer");
  delay(500);
  vfdclear();

  setCursor(1);
  vfd.print("Display Characters");
  setCursor(24);
  vfd.print("Code Fonts");
  delay(1000);
  vfdclear();
  vfdreset();
  vfdchars(); // display the characters from 21 to 255
  vfdclear();

  for (int i = 0; i < 80; i++)
  { // function that runs a character across the vfd
    setCursor(i);
    vfd.write(0xF4); // I got funny symbol with the Datasheet
    delay(100);
    setCursor(i);
    vfd.print(" ");
  }
  vfdclear();
  setCursor(0);
  vfd.print("Follow us  Instagram");
  setCursor(9);
  vfd.write(0xF7); // arrow symbol obtained with the datasheet
  setCursor(24);
  vfd.print("@e_Smartlabs");
  delay(5000);
  vfdclear();
  setCursor(0);
  vfd.print("Follow us   twitter");
  setCursor(9);
  vfd.write(0xF7); // right arrow symbol
  setCursor(24);
  vfd.print("@e_Smartlabs");
  delay(5000);
  vfdclear();
  setCursor(1);
  vfd.print("What is your code?");
  delay(5000);
  setCursor(1); // This achieves delete characters to the right
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(50);
  vfd.write(" ");
  delay(1000);
  setCursor(3);
  vfd.print("vfd Serial UART");
  setCursor(22);
  vfd.print("FUTABA M202SD01LJ");
  delay(20000);
  vfdclear();
}
