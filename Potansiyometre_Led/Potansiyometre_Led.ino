int TimeValue;

void setup() {
  // put your setup code here, to run once:
  TimeValue = 200;

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
  Serial.println("Acilan LED : " + String(openPin));

  Serial.println();
  
  for(int i = 4; i < 9; i++){
    if(i != openPin){
      digitalWrite(i, 0);
    }
    else{
      digitalWrite(i, 1);
    }
  }

  delay(TimeValue);
}
