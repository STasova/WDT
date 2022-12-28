void setup() {
  Serial.begin(38400);
  pinMode(A7, OUTPUT); // Attiniy
  Serial.println("Resetlendi");
}

void loop() {
  digitalWrite(A7,!digitalRead(A7));//Attiny 15sn ye ayarlı,
  Serial.print("A7 = ");
  Serial.println(digitalRead(A7));
  delay(16000); //14000
}
