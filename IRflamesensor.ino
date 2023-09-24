#define sensorPin D5     // Deklarasi sensor terhubung pada pin D5

int bacasensor = 0;      // Nilai awal sensor 0

void setup() {
  pinMode(sensorPin, INPUT); // Deklarasi variabel sensor sebagai input
  Serial.begin(115200);
}

void loop() {
  bacasensor = digitalRead(sensorPin); // Instruksi untuk membaca nilai digital sensor
  Serial.print("Digital value: ");     // Tampilkan nilai digital sensor pada serial monitor
  Serial.println(bacasensor);
  
  if (bacasensor == LOW) {
    Serial.println("Api terdeteksi");  // Menampilkan karakter pada serial monitor jika api terdeteksi
  } else {
    Serial.println("Tidak ada nyala api yang terdeteksi"); // Menampilkan karakter pada serial monitor jika tidak ada api
  }
  
  delay(1000);
}
