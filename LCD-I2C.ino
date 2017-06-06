#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Crear el objeto lcd  dirección  0x27 y 16 columnas x 2 filas
LiquidCrystal_I2C lcd(0x26, 16, 2); //
byte A[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
byte B[8] = {
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
  B10000,
};
byte C[8] = {
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
  B01000,
};
byte D[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};
byte E[8] = {
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
  B00010,
};
byte F[8] = {
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
  B00001,
};
byte G[8] = {
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000,
};
void setup() {
  // Inicializar el LCD
  lcd.init();
  //Encender la luz de fondo.
  lcd.backlight();
  //creamos los nuevos caracteres
  lcd.createChar (0, A);
  lcd.createChar (1, B);
  lcd.createChar (2, C);
  lcd.createChar (3, D);
  lcd.createChar (4, E);
  lcd.createChar (5, F);
  lcd.createChar (6, G);
  // Escribimos el texto en el LCD
  lcd.setCursor(0, 0);
  lcd.print("VUMETRO");
}
void loop () {
  for (int cur = 0 ; cur < 15; cur++) {
    for (int cont = 1 ; cont < 6; cont++) {
      lcd.setCursor(cur, 1);
      delay(500);
      if (cur == 0)¨ {
        else{
          if (cont == 1) {
            lcd.setCursor(cur - 1, 1);
            lcd.write(byte(0);
          }
        }
        lcd.write(byte(cont));
      }
    }
    for (int cur = 15 ; cur >= 0; cur--) {
      for (int cont = 5 ; cont >= 0; cont--) {
        lcd.setCursor(cur, 1);
        delay (200);
        lcd.write(byte(cont));
      }
    }
}
