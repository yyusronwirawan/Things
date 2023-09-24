// Mendefinisikan pin sensor PIR sebagai konstanta A0
const int Sensor_Pir = A0;

// Variabel untuk menyimpan keadaan sensor PIR (HIGH atau LOW)
int Keadaan_Sensor;

// Fungsi setup() dijalankan sekali saat mikrokontroler pertama kali dihidupkan
void setup() {
  // Memulai komunikasi serial dengan kecepatan 9600 bps
  Serial.begin(9600);

  // Mengatur pin A0 sebagai input (tempat tersambungnya sensor PIR)
  pinMode(A0, INPUT);

  // Jeda 100 milidetik untuk stabilisasi
  delay(100);
}

// Fungsi loop() dijalankan terus menerus setelah setup() selesai
void loop() {
  // Membaca keadaan sensor PIR (HIGH jika mendeteksi pergerakan, LOW jika tidak)
  Keadaan_Sensor = digitalRead(Sensor_Pir);

  // Memeriksa apakah sensor PIR mendeteksi pergerakan (HIGH)
  if (Keadaan_Sensor == HIGH) {
    // Jika sensor mendeteksi pergerakan, mencetak pesan ke Serial Monitor
    Serial.println("Sensor Mendeteksi Pergerakan");
  }
  else {
    // Jika sensor tidak mendeteksi pergerakan, mencetak pesan ke Serial Monitor
    Serial.println("Sensor Tidak Mendeteksi Pergerakan");
  }

  // Jeda 1 detik sebelum membaca sensor lagi
  delay(1000);
}
