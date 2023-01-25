#include "Wire.h"
#define DS3231_I2C_ADDRESS 0x68

#define LATCH_DIO 4
#define CLK_DIO 7
#define DATA_DIO 8
 
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};


const byte leterH = B10001001;
const byte kropka = B01111111;
int com_status;
int s_index;
int zapis = 1234;
 
void setup (){
  Wire.begin();
  pinMode(LATCH_DIO,OUTPUT);
  pinMode(CLK_DIO,OUTPUT);
  pinMode(DATA_DIO,OUTPUT); 
  com_status = 0;
  Serial.begin(38400);
}
 
 
void loop(){

  if(Serial.available()>0){
    char znak = Serial.read();

    if(znak == 'T'){
      Serial.println(displayTemperature());
    }
    else
      if(znak == 'S'){
      int liczba = Serial.parseInt();
      zapis = liczba;
      if(zapis > 9999){
        Serial.println("Blad!");
      }
    }
    else{
      zapis = 0000;
    }
  }
  WriteNumber(zapis);
}
 
void WriteNumber(int Number){
  WriteNumberToSegment(0 , Number / 1000);
  WriteNumberToSegment(1 , (Number / 100) % 10);
  WriteNumberToSegment(2 , (Number / 10) % 10);
  WriteNumberToSegment(3 , Number % 10);
}
 
void WriteNumberToSegment(byte Segment, byte Value){
  digitalWrite(LATCH_DIO,LOW); 
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_MAP[Value]);
  shiftOut(DATA_DIO, CLK_DIO, MSBFIRST, SEGMENT_SELECT[Segment] );
  digitalWrite(LATCH_DIO,HIGH);    
}

byte displayTemperature()
{ 
   byte data = 0xFF;
 
  Wire.beginTransmission(0x68);
  Wire.write(0x11); // the integer portion
  Wire.endTransmission();
  
  Wire.requestFrom(0x68,1 );
   if (Wire.available()) { data = Wire.read();}
    
  return data;
}
