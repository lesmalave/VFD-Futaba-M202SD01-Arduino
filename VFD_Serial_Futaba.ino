// Code worked for VFD Futaba M202SD01LJ
// Luis Malavé 2018 @lesmalave @e_smartlabs (twitter & Instagram)
// luisbmalave@gmail.com

#include <SoftwareSerial.h>
SoftwareSerial VFD(2, 3); // (rx, tx) Only connect the TX pin of the arduino to the RX pin of the display

void setup() {
  VFD.begin(9600); // Serial port is set to 9600 bauds supported by VFD
  VFDreset();
  VFDclear();
}

void loop() {
  setCursor(3); // 4 position on VFD
  cursormode(88); //Cursor mode BLINKING
  delay(4000);
  //cursormode(0);
  VFDhorizontaltab();
  setCursor(4);
  VFD.write("W");
  delay(200);
  VFD.write("e");
  delay(200);
  VFD.write("l");
  delay(200);
  VFD.write("c");
  delay(200);
  VFD.write("o");
  delay(200);
  VFD.write("m");
  delay(200);
  VFD.write("e");
  delay(300);
  VFD.write(" ");
  delay(200);
  VFD.write("t");
  delay(200);
  VFD.write("o");
  delay(200);
  VFD.write(" ");
  delay(200);
  setCursor(23); // 2nd line
  VFD.write("e");
  delay(200);
  VFD.write(" ");
  delay(200);
  VFD.write("S");
  delay(200);
  VFD.write("m");
  delay(200);
  VFD.write("a");
  delay(200);
  VFD.write("r");
  delay(200);
  VFD.write("t");
  delay(200);
  VFD.write(" ");
  delay(200);
  VFD.write("L");
  delay(200);
  VFD.write("a");
  delay(200);
  VFD.write("b");
  delay(200);
  VFD.write("s");
  delay(2000);

  cursormode(255); //Cursor mode LIGHT

  for (int positionCounter = 0; positionCounter < 40; positionCounter++) {
    VFDbackspace (); // Clear the display to the left counting from position 40 to position 0
    delay(50);
  }
  cursormode(0); //Cursor mode NO LIGHT

  VFDclear();

  setCursor(1); // 1st line
  VFD.print("Using VFD Serial");
  setCursor(21); // 2nd line
  VFD.print("FUTABA M202SD01LJ");
  delay(2000);
  VFDclear();
  setCursor(1);
  VFD.print("    Now a sample ");
  setCursor(20);
  VFD.print("    Dimmer control ");

  for (int i = 0; i < 3; i++) { // Turn the display on and off 3 times (function "for")
    VFDdimmer(0);
    delay(250);
    VFDdimmer(255);
    delay(800);
  }
  delay(2000);
  VFDclear();
  VFDdimmer(20); // dimmer 20%
  setCursor(4);
  VFD.print("20% Dimmer");
  delay(500);
  VFDclear();
  VFDdimmer(40);
  setCursor(4);
  VFD.print("40% Dimmer");
  delay(500);
  VFDclear();
  VFDdimmer(60);
  setCursor(4);
  VFD.print("60% Dimmer");
  delay(500);
  VFDclear();
  VFDdimmer(80);
  setCursor(4);
  VFD.print("80% Dimmer");
  delay(500);
  VFDclear();
  setCursor(4);
  VFDdimmer(100);
  VFD.print("100% Dimmer");
  delay(500);
  VFDclear();

  setCursor(1);
  VFD.print("Display Characters");
  setCursor(24);
  VFD.print("Code Fonts");
  delay(1000);
  VFDclear();
  VFDreset();
  VFDchars(); // display the characters from 21 to 255
  VFDclear();

  for (int i = 0; i < 80; i++) { // function that runs a character across the VFD  
    setCursor(i);
    VFD.write(0xF4); //I got funny symbol with the Datasheet
    delay(100);
    setCursor(i);
    VFD.print(" ");
  }
  VFDclear();
  setCursor(0);
  VFD.print("Follow us  Instagram");
  setCursor(9);
  VFD.write(0xF7); // arrow symbol obtained with the datasheet
  setCursor(24);
  VFD.print("@e_Smartlabs");
  delay(5000);
  VFDclear();
  setCursor(0);
  VFD.print("Follow us   twitter");
  setCursor(9);
  VFD.write(0xF7); //right arrow symbol
  setCursor(24);
  VFD.print("@e_Smartlabs");
  delay(5000);
  VFDclear();
  setCursor(1);
  VFD.print("What is your code?");
  delay(5000);
  setCursor(1); // This achieves delete characters to the right
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(50);
  VFD.write(" ");
  delay(1000);
  setCursor(3);
  VFD.print("VFD Serial UART");
  setCursor(22);
  VFD.print("FUTABA M202SD01LJ");
  delay(20000);
  VFDclear();
}
