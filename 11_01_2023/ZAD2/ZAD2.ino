#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2); //rozdzielczosc
  pinMode(A0,INPUT); 
  Serial.begin(9600);
}

//R - 0.00
//D - 1.49
//L - 2.33
//U - 0.64
//NIC - 5

void loop() {
  lcd.setCursor(0, 0);
  double val = (analogRead(A0)/204.6);
  
  if(val < 0.50){
    Serial.println("RIGHT");
  }
  else
    if(val > 0.5 && val < 1.00){
      Serial.println("UP");
  }  
  else
    if(val < 1.50){
      Serial.println("DOWN");
    }
  else
    if(val < 2.50){
      Serial.println("LEFT");
    }  
  else
    if(val < 5.50 ){
    }
  if (Serial.available() > 0) {
    lcd.print(Serial.readString());
  }
  delay(300);
}
