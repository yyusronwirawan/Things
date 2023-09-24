// Mendefinisikan pin sensor sebagai konstanta A0
const int Sensor = A0;

// Nilai maksimum untuk kualitas udara bersih
int maxudarabersih = 100;

void setup() {
  // Memulai komunikasi serial dengan kecepatan 9600 bps
  Serial.begin(9600);

  // Mengatur pin A0 sebagai input (tempat tersambungnya sensor)
  pinMode(A0, INPUT);
}

void loop() {
  // Membaca data analog dari sensor
  int dataSensor = analogRead(Sensor);

  // Mencetak nilai dataSensor ke Serial Monitor
  Serial.print(dataSensor);

  // Mencetak spasi untuk pemisah
  Serial.print(" ");

  // Memeriksa apakah kualitas udara melebihi nilai maksimum
  if (dataSensor > maxudarabersih)
    // Jika melebihi, mencetak pesan "Kualitas Udara Tidak Baik"
    Serial.println("Kualitas Udara Tidak Baik");
  else 
    // Jika tidak melebihi, mencetak pesan "Kualitas Udara Baik"
    Serial.println("Kualitas Udara Baik");
  
  // Jeda selama 1 detik sebelum membaca sensor lagi
  delay(1000);
}
