#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); //rozdzielczosc
  pinMode(A0,INPUT); 
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(analogRead(A0)/204.6);
  //lcd.print(wartosc);

  lcd.setCursor(0, 1);
  lcd.print(digitalRead(A0));
  //Serial.println(analogRead(A0)); //1023 = 5v
  delay(300);
}
