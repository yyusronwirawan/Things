const int SoilSensor = A0;  // Mendefinisikan pin A0 sebagai pin untuk sensor kelembaban tanah

void setup() {
  Serial.begin(9600);  // Memulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  float kelembabanTanah;  // Variabel untuk menyimpan nilai kelembaban tanah
  int hasilPembacaan = analogRead(SoilSensor);  // Membaca nilai analog dari sensor

  // Menghitung persentase kelembaban tanah berdasarkan hasil pembacaan sensor
  kelembabanTanah = (100 - ((hasilPembacaan / 1023.00) * 100));

  // Mencetak hasil kelembaban tanah ke Serial Monitor
  Serial.print("Persentase Kelembaban Tanah = ");
  Serial.print(kelembabanTanah);
  Serial.println("%");

  delay(1000);  // Jeda selama 1 detik sebelum membaca sensor lagi
}
