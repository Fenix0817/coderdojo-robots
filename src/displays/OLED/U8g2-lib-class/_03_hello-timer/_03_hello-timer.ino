/*

  Hello World using u8g2 library
  
  
https://github.com/olikraus/u8g2/wiki/u8g2reference#drawstr.  

*/

#include <Arduino.h>
#include <U8g2lib.h>
#include <SPI.h>


//U8G2_SSD1306_128X64_NONAME_F_8080 u8g2(U8G2_R0, 13, 11, 2, 3, 4, 5, 6, A4, /*enable=*/ 7, /*cs=*/ 10, /*dc=*/ 9, /*reset=*/ 8);

// The pins I used on the Arduino Nano
// See https://github.com/olikraus/u8g2/wiki/setup_tutorial
#define RES_PIN 8 //  for SPI mode the RES pin becomes "Chip Select".
#define DC_PIN 9 // Also known as address 0 or A0, not analog 0
#define CS_PIN 10 // chip select
// We are using a 4 wire hardware SPI communications system.  Data is on pin 11 and clock on 13
// U8G2_R0 is the rotation number
// The Frame buffer option (1,2,F) should be 1 due limitations of memory.  1 uses under 32% of 2K RAM
U8G2_SSD1309_128X64_NONAME2_1_4W_HW_SPI u8g2(U8G2_R0, CS_PIN, DC_PIN, RES_PIN);

// 20 character buffer for converting counter to an integer
char buf[20];
int counter = 0;

void setup(void) {
  pinMode(DC_PIN, OUTPUT);
  digitalWrite(DC_PIN, 0);	// default output in I2C mode for the SSD1306 test shield: set the i2c adr to 0
  u8g2.begin();
  // load standard 20px high font
  u8g2.setFont(u8g_font_unifont);
}

void loop() {
  u8g2.firstPage();
  do {
    u8g2.drawStr(0,10,"Hello World!");
    // convert the integer into a string
    sprintf(buf, "1/10 sec: %d", counter);
    u8g2.drawStr(0,24,buf);
    // draw a horizontal line at 50 pixels down
    u8g2.drawHLine(0, 50, 127);
  } while ( u8g2.nextPage() );
  delay(100);
  counter++;
}


