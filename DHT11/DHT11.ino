#include <dht11.h>
#define DHT11PIN 12
#define TIME 2000

dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  for (byte i = 4; i < 9; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(A0, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  Serial.println("Ölçüm yapılıyor. Bekleyiniz...");
  delay(TIME);

  if (chk != 0) {
    Serial.println("NEM (%) : " + String((float)DHT11.humidity));

    Serial.println("SICAKLIK (C) : " + String((float)DHT11.temperature));

    Serial.println("SICAKLIK (F) : " + String((float)DHT11.fahrenheit()));

    Serial.println("SICAKLIK (K) : " + String((float)DHT11.kelvin()));

    Serial.println("");
    humidityInfo((float)DHT11.humidity);

    temperatureInfo((float)DHT11.temperature, "SICAKLIK (C)");
    temperatureInfo((float)DHT11.fahrenheit(), "SICAKLIK (F)");
    temperatureInfo((float)DHT11.kelvin(), "SICAKLIK (K)");
  }
  else {
    Serial.println("DHT11 ile iletisim kurulamadı!!");
  }

  Serial.println();

  delay(TIME);
}

void humidityInfo(float value) {
  int potValue = map(analogRead(A0), 0, 1023, 0, 100);
  Serial.println("Belirlenen deger : " + String(potValue));

  if (value <= potValue) {
    Serial.println("NEM Belirlenen degere esit veya degerin altında");
  }
  else {
    Serial.println("NEM Belirlenen degerin ustunde");
  }
}

void temperatureInfo(float value, String type) {
  float potValue = 0;
  if (type == "SICAKLIK (C)") {
    potValue = map(analogRead(A0), 0, 1023, -40, 80);
  }
  else if (type == "SICAKLIK (F)") {
    potValue = map(analogRead(A0), 0, 1023, -40, 176);
  }
  else if (type == "SICAKLIK (K)") {
    potValue = map(analogRead(A0), 0, 1023, -233.15, 353.15);
  }

  Serial.println("Belirlenen deger : " + String(potValue));
  if (value <= potValue) {
    Serial.println(type + " Belirlenen degere esit veya degerin altında");
  }
  else {
    Serial.println(type + " NEM Belirlenen degerin ustunde");
  }
}
