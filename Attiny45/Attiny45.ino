/*Attiny45
   https://www.youtube.com/watch?v=TUlzOD9T3nI attiny45 ve 85 için
*/
volatile long int bekle = 0;
volatile long int basla;
void setup()
{
  pinMode(4, OUTPUT);//Buzzer,PB4=3 nolu bacağı
  pinMode(0, OUTPUT);//PB0=5 nolu bacağı//led bağlı
  pinMode(2, INPUT_PULLUP); //PB2=7 nolu bacağı=INT0==>Arduino'nun A7=21 nolu bacağına bağlı
  attachInterrupt(0, devam, CHANGE); //INT0=7 nolu bacağı
  basla = millis();
}

void loop() {
  bekle = millis() - basla;
  if (bekle > 15000) // ayarlamak istediğin süreyi 15000 ms yerine girebilirsin, Max=~49 güne denk gelen rakamı aşmamalı (look at "Unsigned long" value)
  {
    pinMode(3, OUTPUT);//PB3=2nolu Bacağı Arduino'nun resetine bağlı
    digitalWrite(3, LOW);
    delay(10);
    for (int i = 0; i < 3; i++)
    {
      digitalWrite(4, HIGH);//Buzzer,PB4=3 nolu bacağı
      delay(400);
      digitalWrite(4, LOW);
      delay(100);
    }
    pinMode(3, INPUT_PULLUP); //PB3=2nolu bacağın kullanımını kapatıyor
    bekle = 0;
    basla = millis();
  }
}

void devam() {
  detachInterrupt(0);
  bekle = 0;
  basla = millis();
  for (int i = 0 ; i < 2; i++)
  {
    digitalWrite(0, LOW); //PB0=5nolu bacağı,LED
    delay(30);
    digitalWrite(0, HIGH); //LED
    delay(70);
  }
  digitalWrite(0, LOW); //LED
  attachInterrupt(0, devam, CHANGE);
}
