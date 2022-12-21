void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Hello World!");
}

void loop() {
  // put your main code here, to run repeatedly:

  if(Serial.available()>0){
    String teststr = Serial.readString();  //read until timeout
    Serial.println(teststr);
    while (Serial.available() == 0) {}     //wait for data available
    teststr = Serial.readString();  //read until timeout
    Serial.println(teststr);
  }
  Serial.println(":)");
}
