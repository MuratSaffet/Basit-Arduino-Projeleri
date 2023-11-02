int TimeValue;
int BorderPot;
int BorderLdr;
int BorderNtc;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(A0, INPUT); //Potansiyometre
  pinMode(A1, INPUT); //Ldr (isik)
  pinMode(A2, INPUT); //Ntc (sicaklik)

  pinMode(6, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT); //Buzzer

  TimeValue = 1000;
  BorderPot = 650;
  BorderLdr = 900;
  BorderNtc = 525;
}

void loop() {
  // put your main code here, to run repeatedly:
  int valuePot = analogRead(A0);
  Serial.println("Potansiyometre : " + String(valuePot));

  int valueLdr = analogRead(A1);
  Serial.println("Ldr (isik) : " + String(valueLdr));

  int valueNtc = analogRead(A2);
  Serial.println("Ntc (sicaklik) : " + String(valueNtc));

  Serial.println();
  if(valuePot > BorderPot){
    digitalWrite(13, 1);
  }
  else{
    digitalWrite(13, 0);
  }

  if(valueLdr > BorderLdr){
    digitalWrite(8, 1);
  }
  else{
    digitalWrite(8, 0);
  }

  if(valueNtc > BorderNtc){
    digitalWrite(6, 1);
  }
  else{
    digitalWrite(6, 0);
  }
  delay(TimeValue);
}
