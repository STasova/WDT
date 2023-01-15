void setup() {
  Serial.begin(38400);
  pinMode(A7, OUTPUT); // Attiniy
  Serial.println("Resetlendi");
}

void loop() {
  digitalWrite(A7,!digitalRead(A7));//Attiny 15sn ye ayarlı,
  Serial.print("A7 = ");
  Serial.println(digitalRead(A7));
  delay(18000); //WDT attinyde 15000'e ayarlı olduğu için 15 sn üzerindeki gecikmelerde 15. snyede attinye ulaşamadığı için reseti atacaktır.
}
