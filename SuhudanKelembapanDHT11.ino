#include "DHT.h"  // Mengimpor pustaka DHT untuk sensor DHT

#define DHTPIN D7     // Mendefinisikan pin yang digunakan untuk sensor DHT
#define DHTTYPE DHT11 // Mendefinisikan tipe sensor DHT yang digunakan (DHT11)

DHT dht(DHTPIN, DHTTYPE); // Membuat objek DHT dengan pin dan tipe yang telah didefinisikan

void setup() {
  Serial.begin(9600); // Inisialisasi komunikasi serial dengan kecepatan 9600 bps
  dht.begin();        // Inisialisasi sensor DHT
}

void loop() {
  float h = dht.readHumidity();    // Membaca kelembapan dari sensor DHT
  float t = dht.readTemperature(); // Membaca suhu dari sensor DHT

  Serial.print(F("Kelembapan: ")); // Menampilkan teks "Kelembapan: " ke dalam serial monitor
  Serial.print(h);                 // Menampilkan nilai kelembapan ke dalam serial monitor
  Serial.print("\n");              // Menampilkan baris baru

  Serial.print(F("  Suhu: "));     // Menampilkan teks "Suhu: " ke dalam serial monitor
  Serial.print(t);                 // Menampilkan nilai suhu ke dalam serial monitor
  Serial.print(F("°C "));          // Menampilkan teks "°C " ke dalam serial monitor
  delay(2000);                     // Menunda selama 2 detik sebelum membaca data lagi
}
