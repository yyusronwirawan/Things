#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

byte gammatable[256]; // Tabel gamma untuk koreksi warna
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Membuat objek sensor warna TCS34725
LiquidCrystal_I2C lcd(0x27, 16, 2); // Membuat objek LCD dengan alamat I2C 0x27 dan ukuran 16x2

#define commonAnode false // Mode koneksi LED RGB (common cathode)

void setup() {
  Serial.begin(9600); // Memulai komunikasi serial dengan kecepatan 9600 bps
  lcd.init(); // Menginisialisasi LCD
  lcd.backlight(); // Menyalakan latar belakang LCD

  lcd.begin(16, 2); // Mengatur ukuran LCD menjadi 16 karakter dan 2 baris
  lcd.clear(); // Menghapus layar LCD
  lcd.setCursor(1, 0); // Mengatur kursor LCD di kolom 1, baris 0
  lcd.print("ArduinoKita"); // Menampilkan pesan "ArduinoKita" di LCD
  delay(3000); // Jeda selama 3 detik

  lcd.setCursor(4, 1); // Mengatur kursor LCD di kolom 4, baris 1
  if (tcs.begin()) { // Menginisialisasi sensor warna TCS34725
    lcd.print("Ready"); // Menampilkan pesan "Ready" jika sensor siap
  } else {
    lcd.print("Sensor Error"); // Menampilkan pesan "Sensor Error" jika ada masalah dengan sensor
    while (1); // Menghentikan program jika ada masalah dengan sensor
  }
}

void loop() {
  float red, green, blue; // Variabel untuk menyimpan nilai komponen warna RGB
  tcs.setInterrupt(false); // Menonaktifkan interrupt sensor warna
  delay(60); // Jeda 60 ms
  tcs.getRGB(&red, &green, &blue); // Membaca nilai komponen warna RGB
  tcs.setInterrupt(true); // Mengaktifkan kembali interrupt sensor warna
  delay(500); // Jeda 500 ms
  lcd.clear(); // Menghapus layar LCD
  lcd.print("Warna: "); // Menampilkan pesan "Warna: " di LCD
  lcd.setCursor(0, 1); // Mengatur kursor LCD di baris 1
  lcd.print("R:"); // Menampilkan pesan "R:"
  lcd.print(int(red)); // Menampilkan nilai komponen merah (red) di LCD
  lcd.print(" G:"); // Menampilkan pesan " G:"
  lcd.print(int(green)); // Menampilkan nilai komponen hijau (green) di LCD
  lcd.print(" B:"); // Menampilkan pesan " B:"
  lcd.print(int(blue)); // Menampilkan nilai komponen biru (blue) di LCD

  // Mengenali warna berdasarkan rentang nilai komponen RGB
  if (red >= 140 && red <= 185 && green >= 30 && green <= 60 && blue >= 40 && blue <= 50) {
    lcd.setCursor(10, 0); // Mengatur kursor LCD di kolom 10, baris 0
    lcd.print("Merah"); // Menampilkan pesan "Merah" di LCD
  }

  if (red >= 35 && red <= 55 && green >= 75 && green <= 85 && blue >= 110 && blue <= 130) {
    lcd.setCursor(10, 0); // Mengatur kursor LCD di kolom 10, baris 0
    lcd.print("Biru"); // Menampilkan pesan "Biru" di LCD
  }

  if (red >= 50 && red <= 70 && green >= 105 && green <= 135 && blue >= 50 && blue <= 80) {
    lcd.setCursor(10, 0); // Mengatur kursor LCD di kolom 10, baris 0
    lcd.print("Hijau"); // Menampilkan pesan "Hijau" di LCD
  }

  delay(1000); // Jeda selama 1 detik sebelum membaca warna lagi
}
