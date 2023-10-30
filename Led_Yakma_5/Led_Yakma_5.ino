int TimeValue;

void setup() {
  // put your setup code here, to run once:
  for(int i = 4; i<12; i++){
    pinMode(i, OUTPUT);//Led
  }
  TimeValue = 1000;
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 4; i < 12; i++){
    digitalWrite(i, 1);
    delay(TimeValue);
    digitalWrite(i, 0);
  }

  for(int i = 11; i >= 4; i--){
    digitalWrite(i, 1);
    delay(TimeValue);
    digitalWrite(i, 0);
  }
}
