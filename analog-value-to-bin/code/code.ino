//LED'lerin bagli oldugu dijital pinler int tipinde dizide saklanir.
int ledPins[] = {3, 2, 8, 9, 10, 11, 12, 13};

void setup() {
  //LED'ler cikis donanimi oldugundan bagli oldugu
  //pinler OUTPUT olarak ayarlanir.
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  //Potansiyometreden okunan degerlerin
  //terminal ekraninda gosterilebilmesi icin
  //9600 baudrate hizinda Seri haberlesme portuna baglanilir.
  Serial.begin(9600);
}

void loop() {
  // Potansiyometrenin bagli oldugu A0 pininden
  // analog olarak deger okunur ve int degiskenine aktarilir.
  int potValue=analogRead(A0);

  //0-1023 arasinda deger okundugundan ve 8 bitlik
  //deger gosterileceginden okunan deger 0-255
  //arasina map edilir.
  int binaryValue = map(potValue, 0, 1023, 0, 255);

  Serial.println(potValue);
  //for dongusu ile LED'lerin pinlerini tutan dizi gezilir.
  for (int i = 0; i < 8; i++) {
    //Map edilmis analog deger ile i'nin 1 bit kaydirilmis
    //haline AND islemi uygulanir ve cikis sinyali olusturulur.
    if (binaryValue & (1 << i)) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

}
