int TimeValue;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A0, INPUT); //Potansiyometre
  pinMode(A1, INPUT); //Ldr (isik)
  pinMode(A2, INPUT); //Ntc (sicaklik)

  TimeValue = 1000;
}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Potansiyometre : " + String(analogRead(A0)));
  Serial.println("Ldr (isik) : " + String(analogRead(A1)));
  Serial.println("Ntc (sicaklik) : " + String(analogRead(A2)) + "\n");
  delay(TimeValue);
}
