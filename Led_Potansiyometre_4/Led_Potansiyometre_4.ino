void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);//Led
  pinMode(5, OUTPUT);//Led
  pinMode(6, OUTPUT);//Led
  pinMode(7, OUTPUT);//Led
  pinMode(8, OUTPUT);//Led
}

void loop() {
  // put your main code here, to run repeatedly:
  openClose(analogRead(A0));//Potansiyometre
}

void openClose(int value){
  for(int i = 4; i<=8;i++){
    digitalWrite(i, 1);
  }
  delay(value);
  
  for(int i = 4; i<=8;i++){
    digitalWrite(i, 0);
  }
  delay(value);
}
