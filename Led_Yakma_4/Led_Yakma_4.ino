// variable definition
int WaitingTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  WaitingTime = 500;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(5, 1);
  digitalWrite(7, 1);
  
  digitalWrite(4, 0);
  digitalWrite(6, 0);
  digitalWrite(8, 0);
  delay(WaitingTime);

  digitalWrite(5, 0);
  digitalWrite(7, 0);
  
  digitalWrite(4, 1);
  digitalWrite(6, 1);
  digitalWrite(8, 1);
  delay(WaitingTime);
}
