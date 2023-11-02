int TimeValue;
void setup() {
  // put your setup code here, to run once:
  TimeValue = 1000;
  Serial.begin(9600);
  
  pinMode(A0, INPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  Serial.println("Potansiyometre değeri: " + String(value));

  int newValue = map(value, 0, 1023, 0, 255);
  Serial.println("Potansiyometre YENI değeri: " + String(newValue));

  analogWrite(6, newValue);

  delay(TimeValue);  
}
