const int nilaiMin = 0;        // Nilai minimum pembacaan analog
const int nilaiMaks = 1024;    // Nilai maksimum pembacaan analog

void setup()
{
  Serial.begin(9600);          // Memulai komunikasi serial dengan kecepatan 9600 bps
}

void loop()
{
  int hasil = analogRead(A0);  // Membaca nilai analog dari pin A0
  int range = map(hasil, nilaiMin, nilaiMaks, 0, 3);  // Mengonversi nilai analog ke dalam rentang 0-3

  switch (range)
  {
    case 0:
      Serial.print(hasil);           // Mencetak nilai analog
      Serial.println(" HUJAN");      // Mencetak pesan "HUJAN" jika range adalah 0
      break;

    case 1:
      Serial.print(hasil);           // Mencetak nilai analog
      Serial.println(" AWAS HUJAN"); // Mencetak pesan "AWAS HUJAN" jika range adalah 1
      break;

    case 2:
      Serial.print(hasil);           // Mencetak nilai analog
      Serial.println(" TIDAK HUJAN"); // Mencetak pesan "TIDAK HUJAN" jika range adalah 2
      break;
  }
  delay(1000);  // Menunggu selama 1 detik sebelum membaca ulang
}
