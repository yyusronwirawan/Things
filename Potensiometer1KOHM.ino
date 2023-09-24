int pot = A0;  // Mendefinisikan pin A0 sebagai input potensiometer

void setup() {
  Serial.begin(9600);   // Memulai komunikasi serial dengan kecepatan 9600 bps
  pinMode(pot, INPUT);  // Mengatur pin potensiometer sebagai input
}

void loop() {
  // Membaca nilai analog dari potensiometer
  float nilai = analogRead(pot);

  // Menghitung nilai tegangan dari nilai analog
  float nilai_v = nilai * (5.0 / 1023.0);

  // Mencetak nilai analog ke Serial Monitor
  Serial.print("Nilai analog: ");
  Serial.println(nilai);

  // Mencetak nilai tegangan (V) ke Serial Monitor
  Serial.print("Tegangan (V): ");
  Serial.println(nilai_v);

  delay(1000);  // Jeda 1 detik sebelum membaca ulang
}
