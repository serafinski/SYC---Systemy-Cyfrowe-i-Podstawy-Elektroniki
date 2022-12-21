void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Wprowadz rownanie: ");
  while (Serial.available() == 0) {}     //wait for data available
  int num1 = Serial.parseInt();  //read until timeout
  char znak= Serial.read();
  int num2 = Serial.parseInt();

  if(znak=='+'){
    int suma = num1+num2;
    Serial.println(suma);
  }
  else
    if(znak=='-'){
      int odejmowanie = num1-num2;
      Serial.println(odejmowanie);
    }
  else
    if(znak=='*'){
      int mnozenie = num1*num2;
      Serial.println(mnozenie);
    }
  else{
    if(znak=='/'){
      int dzielenie = num1/num2;
      Serial.println(dzielenie);
    }
  }
}
