#include <Wire.h>             // Library untuk pengaksesan I2C
#include <Adafruit_BME280.h>  // Library untuk sensor BME280
#include <Adafruit_Sensor.h>

#define SEALEVELPRESSURE_HPA (1013.25) // Nilai tekanan laut standar (hPa)

Adafruit_BME280 bme; // Penggunaan objek BME280 dengan komunikasi I2C

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan kecepatan 9600 bps

  if (!bme.begin(0x76)) { // Mencoba inisialisasi sensor BME280 dengan alamat 0x76
    Serial.println("Tidak ada sensor BME280, Coba cek rangkaianmu!");
    while (1);
  }
}

void loop() {
  // Membaca dan mencetak data suhu dalam derajat Celsius
  Serial.print("Suhu =");
  Serial.print(bme.readTemperature());
  Serial.println(" *C");

  // Membaca dan mencetak data kelembaban dalam persentase (%)
  Serial.print("Kelembaban = ");
  Serial.print(bme.readHumidity());
  Serial.println(" %");

  // Membaca dan mencetak data tekanan atmosfer dalam hektopascal (hPa)
  Serial.print("Pressure = ");
  Serial.print(bme.readPressure() / 100.0F);
  Serial.println(" hPa");

  // Membaca dan mencetak data ketinggian perkiraan di atas permukaan laut
  Serial.print("Approx. Altitude = ");
  Serial.print(bme.readAltitude(SEALEVELPRESSURE_HPA));
  Serial.println(" m");

  Serial.println(); // Menambahkan baris kosong untuk pemisah
  delay(1000); // Jeda selama 1 detik sebelum membaca data lagi
}
