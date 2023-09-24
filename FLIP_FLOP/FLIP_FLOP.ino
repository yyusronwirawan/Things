void setup() {
  // Mengatur pin D1 hingga D8 sebagai OUTPUT
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
}

void loop() {
  // Mengaktifkan D1 dan menunggu 1 detik
  digitalWrite(D1, HIGH);
  delay(1000);

  // Mematikan D1 dan menunggu 1 detik
  digitalWrite(D1, LOW);

  // Mengaktifkan D32 dan menunggu 1 detik
  digitalWrite(D2, HIGH);
  delay(1000);

  // Mematikan D2 dan menunggu 1 detik
  digitalWrite(D2, LOW);

  // Lanjutkan dengan pola yang sama untuk pin D3 hingga D8
  digitalWrite(D3, HIGH);
  delay(1000);
  digitalWrite(D3, LOW);

  digitalWrite(D4, HIGH);
  delay(1000);
  digitalWrite(D4, LOW);

  digitalWrite(D5, HIGH);
  delay(1000);
  digitalWrite(D5, LOW);

  digitalWrite(D6, HIGH);
  delay(1000);
  digitalWrite(D6, LOW);

  digitalWrite(D7, HIGH);
  delay(1000);
  digitalWrite(D7, LOW);

  digitalWrite(D8, HIGH);
  delay(1000);
  digitalWrite(D8, LOW);
}
