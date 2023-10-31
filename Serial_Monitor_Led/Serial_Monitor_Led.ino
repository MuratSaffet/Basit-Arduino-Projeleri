int TimeValue;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  TimeValue = 500;

  Serial.println("Led'i açmak için (a/A) tusuna basiniz");
  Serial.println("Led'i kapatmak için (k/K) tusuna basiniz");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char choice = Serial.read();

    if(choice == 'a' || choice == 'A'){
      digitalWrite(4, 1);
      Serial.println("Led acildi...");
      Serial.println("Ledi açmak için (a/A) tusuna basiniz");
      Serial.println("Ledi kapatmak için (k/K) tusuna basiniz");
    }
    if(choice == 'k' || choice == 'K'){
      digitalWrite(4, 0);
      Serial.println("Led kapandi...");
      Serial.println("Ledi açmak için (a/A) tusuna basiniz");
      Serial.println("Ledi kapatmak için (k/K) tusuna basiniz");
    }

    while(Serial.available()){
      Serial.read();
    }
  }

  delay(TimeValue);
}
