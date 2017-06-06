#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);
int pos = 0;
int fil = 1;
const byte ROWS = 4; // Cuatro filas
const byte COLS = 4; // Cuatro columnas
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 11, 10, 9, 8 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 7, 6, 5, 4 }; 
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
char key;
void setup()
{
 lcd.init();
 lcd.backlight();
 lcd.setCursor(pos, fil); 
}

void loop()
{
   if (key == '*')
   {
   pos =0;
   lcd.clear();
   lcd.setCursor(pos, fil);
   }
   if (pos <= 16)
   {
   lcd.setCursor(pos, fil);
   key = kpd.getKey();
   }
   else
   {
    pos =0;
    lcd.clear();
    lcd.setCursor(pos, fil);
    }
  if(key)  // Check for a valid key.
  {
 lcd.print(key);
 pos = pos + 1;

  }
 
}
