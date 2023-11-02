void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT); //Potansiyometre

  for(byte i = 4; i < 9; i++){
    pinMode(i, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int valuePot = analogRead(A0);
  Serial.println("Potansiyometre : " + String(valuePot));
  
  int openPin = map(valuePot, 0, 1023, 4, 8);
  
  Serial.println();

  String openPins = "";
  for(int i = 4; i < 9; i++){
    if(i >= openPin){
      digitalWrite(i, 1);
      openPins += ", " + String(i);
    }
    else{
      digitalWrite(i, 0);
    }
  }
  
  Serial.println("Acilan LED'ler " + openPins);
  delay(valuePot);
}
