/*
  => Ogrenci Adi-Soyadi: Aziz Can HAMASOGLU
  => Ogrenci No        : 200260094
*/

// LM35 Sıcaklık Sensörü
int sensorPin = A0;

// DC Motor
int enablePin = 10;
int in1Pin = 8;
int in2Pin = 9;

void setup() {
  // Pinleri ayarla
  pinMode(enablePin, OUTPUT);
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  
  // Hiz kontrol pini icin baslangicta sifir degerini ayarla
  analogWrite(enablePin, 0);
}

void loop() {
  // Sicaklik degerini oku
  int sensorValue = analogRead(sensorPin);

  // Sicaklik degerini Celsius'a dönüştür
  float celsius = (sensorValue * 5.0) / 1023.0 * 100.0;

  // Motor hizini haritalandir.
  int motorSpeed = map(sensorValue, 0, 1023, 0, 255);
  digitalWrite(in1Pin,HIGH);
  digitalWrite(in2Pin,LOW);
  analogWrite(enablePin, motorSpeed);

  delay(1000); // 1 saniye bekle
}
