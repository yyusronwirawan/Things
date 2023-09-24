const int ldrPin = A0;  // Pin analog untuk sensor LDR

void setup() {
  Serial.begin(9600);  // Memulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  // Membaca nilai analog dari sensor LDR
  int ldrValue = analogRead(ldrPin);

  // Mencetak nilai LDR ke Serial Monitor
  Serial.print("Nilai LDR: ");
  Serial.println(ldrValue);

  // Tambahkan logika atau tindakan berdasarkan nilai LDR di sini
  // Contoh: jika ldrValue < 500, maka lakukan sesuatu

  delay(1000);  // Jeda 1 detik sebelum membaca sensor lagi
}
