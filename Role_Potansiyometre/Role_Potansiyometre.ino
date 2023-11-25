int BOUNDARY;

void setup() {
  // put your setup code here, to run once:
  pinMode(9, OUTPUT);
  Serial.begin(9600);
  BOUNDARY = 500;
}

void loop() {
  // put your main code here, to run repeatedly:
  int value = analogRead(A0);
  Serial.println("POTANSIYOMETRE = " + String(value));
  
  if (value < 500) // Potansiyometre
  {
    digitalWrite(9, 0);
  }
  else
  {
    digitalWrite(9, 1);
  }

  delay(BOUNDARY);
}
