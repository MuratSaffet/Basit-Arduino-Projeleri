// variable definition
int WaitingTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  WaitingTime = 200;
}

void loop() {
  // put your main code here, to run repeatedly:

  // put your main code here, to run repeatedly:
  // high
  digitalWrite(4, 1);
  digitalWrite(8, 1);
  delay(WaitingTime);

  digitalWrite(5, 1);
  digitalWrite(7, 1);
  delay(WaitingTime);  

  digitalWrite(6, 1);
  delay(WaitingTime); 

  //low
  digitalWrite(6, 0);
  delay(WaitingTime); 

  digitalWrite(5, 0);
  digitalWrite(7, 0);
  delay(WaitingTime);
  
  digitalWrite(4, 0);
  digitalWrite(8, 0);
  delay(WaitingTime);
}
