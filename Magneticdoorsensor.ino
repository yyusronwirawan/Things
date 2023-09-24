int state = 0; // Variabel untuk menyimpan status pintu (terbuka/tutup)

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan kecepatan 9600 bps
  pinMode(D2, INPUT_PULLUP); // Mengatur pin D2 sebagai INPUT dengan pull-up internal
  pinMode(D3, OUTPUT); // Mengatur pin D3 sebagai OUTPUT untuk LED indikator
}

void loop() {
  int bacaSensor = digitalRead(D2); // Membaca status sensor pintu

  // Memeriksa jika pintu terbuka (HIGH) dan sebelumnya dalam keadaan tertutup
  if (bacaSensor == HIGH && state == 0) {
    Serial.println("Pintu ada yang buka!");
    digitalWrite(D3, HIGH); // Mengaktifkan LED indikator
    state = 1; // Menandai bahwa pintu dalam keadaan terbuka
  }
  // Memeriksa jika pintu tertutup (LOW)
  else if (bacaSensor == LOW) {
    state = 0; // Menandai bahwa pintu dalam keadaan tertutup
    Serial.println("Pintu tertutup.");
    digitalWrite(D3, LOW); // Mematikan LED indikator
  }
  delay(1000); // Jeda selama 1 detik sebelum membaca status pintu lagi
}
