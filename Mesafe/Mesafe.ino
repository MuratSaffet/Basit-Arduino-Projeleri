const int TRIG = 8;
const int ECHO = 12;

float DISTANCE;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(A0, INPUT);
  
  Serial.begin(9600);
}

void loop() {
  calculateDistance();
  printValues();
  delay(analogRead(A0));
}

void calculateDistance() {
  digitalWrite(TRIG, 0);
  delayMicroseconds(10);
  digitalWrite(TRIG, 1);
  delayMicroseconds(10);
  digitalWrite(TRIG, 0);
  long delayValue = pulseIn(ECHO, 1);
  DISTANCE = delayValue * 0.034 / 2;
}

void printValues() {
  Serial.println("DISTANCE : " + String(DISTANCE) + " CM");
}
