
/* 
 || @version 1.0
 || @author Andrew Mascolo
 || @date May 15, 2013
 ||
 || @description
 || Simple use of keypad and LCD
*/
#include <Keypad.h>
#include <Wire.h> 
#include <LiquidCrystal.h>
LiquidCrystal lcd(23, 22, 27, 26, 25, 24);


long Mini = 0;
long Maxi = 0;
double totalMini = 0;
double totalMaxi = 0;
double Divisor = 100;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {35, 34, 33, 32}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {31, 30, 29,28}; //connect to the column pinouts of the keypad

Keypad customKeypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); 

void setup()
{
    lcd.begin(16, 2);
    lcd.setCursor(0,0);
    lcd.print("T. Min");
    lcd.setCursor(10,0);
    lcd.print("T. Max");
}

void seteo() [color=red][b]//subrutina de poenr el digito a la izquerda del lcd, a la derecha es copiar estecambiando //las variables y valores[/b]
{[/color]
  customKey = customKeypad.getKey();
 switch(customKey) 
{
  case '0' ... '9': // This keeps collecting the first value until a operator is pressed "+-*/"
    lcd.setCursor(0,2);
    Mini = Mini * 10 + (customKey - '0');
    lcd.print(Mini);
    break;

    case '=':
    Mini = (totalMini != 0 ? totalMini : Mini);
    lcd.setCursor(0,1);
    totalMini = (float)Mini / (float)Divisor;
    lcd.print(totalMini);
    Mini = 0;
    break;

  case 'C':
    totalMini = 0;
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("T. Min");
    lcd.setCursor(10,0);
    lcd.print("T. Max");
    break;
}
return;
}

void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey) 
  {
      case 'A':
    seteo();// [b][color=red]aqui debo enviarlo a una subrrutina llamada sete[b][/color][/b][/b]o
    //break;

}
}
 
