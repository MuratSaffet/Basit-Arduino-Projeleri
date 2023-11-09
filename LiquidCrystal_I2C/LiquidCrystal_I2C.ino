#include <LiquidCrystal_I2C.h>
#include <dht11.h>

#define TIME 2000
#define DHT11PIN 12

LiquidCrystal_I2C EKRAN(0x27, 16, 2);
dht11 DHT11;

void setup() {
  // put your setup code here, to run once:
  EKRAN.init();
  EKRAN.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int chk = DHT11.read(DHT11PIN);

  EKRAN.setCursor(0, 0); // (sutun, satır)
  EKRAN.print("OLCUM YAPILIYOR...");
  EKRAN.setCursor(0, 1); // (sutun, satır)
  EKRAN.print("BEKLEYINIZ...");
  delay(TIME);

  EKRAN.clear();
  
  if(chk!=0){
    EKRAN.setCursor(0, 0); // (sutun, satır)
    EKRAN.print("NEM(%)-SICAKLIK(C)");
    EKRAN.setCursor(0, 1); // (sutun, satır)
    EKRAN.print(String((float)DHT11.humidity) + " - " + String((float)DHT11.temperature));
  }
  else{
    EKRAN.setCursor(0, 0); // (sutun, satır)
    EKRAN.print("UYARI");
    EKRAN.setCursor(0, 1); // (sutun, satır)
    EKRAN.print("DHT11 ILETISIM YOK");
  }
  
  delay(TIME * 3);
}
