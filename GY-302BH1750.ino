#include <Wire.h>     // Library untuk komunikasi I2C
#include <BH1750.h>   // Library untuk sensor cahaya BH1750

BH1750 lightMeter;    // Membuat objek BH1750 untuk mengakses sensor cahaya

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan kecepatan 9600 bps
  Wire.begin();       // Memulai komunikasi I2C
  lightMeter.begin(); // Memulai sensor cahaya BH1750
  Serial.println(F("BH1750 Test begin"));
}

void loop() {
  float LUX = lightMeter.readLightLevel(); // Membaca tingkat cahaya dalam LUX
  Serial.print("Cahaya: ");
  Serial.print(LUX);
  Serial.println(" LUX"); // Mencetak nilai tingkat cahaya ke Serial Monitor
  delay(1000); // Jeda 1 detik sebelum membaca data cahaya lagi
}
