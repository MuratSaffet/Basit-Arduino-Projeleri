int TimeValue;
String Message;
char VowelLetter[] = {'a', 'e', 'u', 'ı', 'ü', 'i', 'ö', 'o'};

void setup() {
  // put your setup code here, to run once:
  TimeValue = 1000;
  Serial.begin(9600);
  Message = "";

  Serial.println("Bir metin giriniz...");
}

void loop() {
  // put your main code here, to run repeatedly:    
  if(Serial.available()){  
    String text = "";
  
    while(true){
      text = Serial.readString();
      text.trim();//To remove spaces and line break characters at the beginning and end of text
      if(text != ""){
        break;
      }
    }

    Serial.println(text);

    Message += "<== Girilen Metnin Incelenmesi ==>\n";
    
    int totalLetter = text.length();
    Message += "Toplam harf sayisi : " + String(totalLetter) + "\n";
    
    ///
    int totalVowelLetter = 0;
    for(int i=0; i < totalLetter; i++){
      for(int j=0; j < 8; j++){
        //The total number of elements of array VowelLetter is 8 
        if(VowelLetter[j] == text[i]){
          totalVowelLetter ++;
        }
      }
    }
    Message += "Toplam unlu harf sayisi : " + String(totalVowelLetter) + "\n";

    ///
    int totalConsonantLetter = 0;
    for(int i=0; i < totalLetter; i++){
      byte tempData = 0;
      for(int j=0; j < 8; j++){
        //The total number of elements of array VowelLetter is 8 
        if(VowelLetter[j] != text[i]){
          tempData++;
        }
      }
      if(tempData==8){
        totalConsonantLetter ++;
      }
    }
    Message += "Toplam unsuz harf sayisi : " + String(totalConsonantLetter) + "\n";

    ///
    int totalWord = 0;
    if(text != ""){
      for(int i=0; i < totalLetter; i++){
        if(text[i] == ' '){
          totalWord ++;
        }
      }  
      totalWord ++;    
    }
    Message += "Toplam kelime sayisi : " + String(totalWord) + "\n";
    
    Serial.println(Message);

    Message = "";

    Serial.println("Bir metin giriniz...");
  }
  
  delay(TimeValue);
}
