// Use two lines of an LCD display to show large numbers

// The large font spans one characetr with over 2 LCD display lines
// to give a font which is similar to a 7-segment display

#include <LiquidCrystal.h>
#include "BigNum.h"

// LCD display definitions
#define  LCD_ROWS  2
#define  LCD_COLS  16

// LCD pin definitions
#define  LCD_RS    8
#define  LCD_ENA   9
#define  LCD_D4    4
#define  LCD_D5    LCD_D4+1
#define  LCD_D6    LCD_D4+2
#define  LCD_D7    LCD_D4+3

static LiquidCrystal lcd(LCD_RS, LCD_ENA, LCD_D4, LCD_D5, LCD_D6, LCD_D7);
static BigNum bn(&lcd);

// Waiting time between numbers in milliseconds
#define  WAIT_DELAY  1000

void setup()
{
  Serial.begin(57600);
  
  // initialise LCD display
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.print(F("LCD Big Chars"));

  // initialise bigchars
  bn.begin();
  
  lcd.clear();  // clear the display and ...
  lcd.noCursor(); // ... display the cursor
}

void allDigits(void)
{
  for (uint8_t i=0; i<10; i++)
    bn.writeNumber(0, i, i, 1);
}

void loop(void)
{
  static uint16_t  count = 0;

  bn.setSingleFont();
  allDigits();
  delay(10*WAIT_DELAY);
  lcd.clear();
  
  bn.setDoubleFont();
  allDigits();
  delay(10*WAIT_DELAY);
  lcd.clear();
  
  while (true)
  {
    bn.writeNumber(0, 0, count++, 4, true);
    delay(WAIT_DELAY);
  }
}

