#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

const byte ROWS = 4; // Cuatro filas
const byte COLS = 4; // Cuatro columnas
// Define the Keymap
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'#','0','*','D'}
};
// Connect keypad ROW0, ROW1, ROW2 and ROW3 to these Arduino pins.
byte rowPins[ROWS] = { 4, 5, 6, 7 };
// Connect keypad COL0, COL1 and COL2 to these Arduino pins.
byte colPins[COLS] = { 8, 9, 10, 11 }; 
// Create the Keypad
Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
 lcd.init();
 lcd.backlight();
  
 Serial.begin(9600);
}

void loop()
{
   lcd.setCursor(0, 1);
  char key = kpd.getKey();
  if(key)  // Check for a valid key.
  {
 lcd.print(key);

  }
 
}
