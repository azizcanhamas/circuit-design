
int sensorsPins[4][2] ={
  {8,9},    //on
  {10,11},  //sol
  {3,2},    //sag
  {12,13}}; //arka
char *sensorNames[]={"ON","SOL","SAG","ARKA"};

void setup() {
  // Trigger pinleri OUTPUT, Echo pinleri INPUT olarak
  // set ediliyor.
  for(int i=0;i<sizeof(sensorsPins);i+=1){
    pinMode(sensorsPins[i][0],OUTPUT);
    pinMode(sensorsPins[i][1],INPUT);
  }

  // Sanal terminale mesaj gonderebilmek icin
  // Seri porta 9600 baudrate hizinda baglaniliyor.
  Serial.begin(9600);
}

void loop() {
  // Bagli olan tum sensorler dongu araciligiyla geziliyor.
  for(int i=0;i<4;i++){
    //Gecerli sensorun TRIGGER pinini LOW yap.
    digitalWrite(sensorsPins[i][0],LOW);
    delayMicroseconds(2);

    // 10 mikrosaniyelik sinyal gonder ve kes.
    digitalWrite(sensorsPins[i][0],HIGH);
    delayMicroseconds(10);
    digitalWrite(sensorsPins[i][0],LOW);

    // Gonderilen sinyali ECHO pini araciligiyla dinle
    // ardindan mesafeyi hesapla.
    float gecenZaman=pulseIn(sensorsPins[i][1],HIGH);
    float mesafe=gecenZaman*0.034/2;

    // Gecerli sensorun olctugu mesafe degerini
    // sensor ismiyle beraber terminale gonder.
    Serial.print(sensorNames[i]);
    Serial.print(" : ");
    Serial.println(mesafe);
    delay(20);
  }
  // Terminalde verilerin hizli akmamasi icin yavasla
  Serial.println("===================");
  delay(1000);

}
