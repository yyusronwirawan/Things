#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Mengatur alamat LCD ke 0x27 untuk tampilan 16 karakter dan 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // Inisialisasi LCD
  lcd.begin();
  lcd.print("Hello, world!"); // Menampilkan pesan "Hello, world!" pada LCD
  delay(2000); // Jeda 2 detik
}

void loop() {
  lcd.clear(); // Membersihkan tampilan LCD
  delay(2000); // Jeda 2 detik
  lcd.setCursor(0, 0); // Mengatur kursor LCD ke kolom 0, baris 0
  lcd.print("Hi, This is OK?"); // Menampilkan pesan "Hi, This is OK?" pada LCD
  delay(2000); // Jeda 2 detik
  lcd.setCursor(0, 1); // Mengatur kursor LCD ke kolom 0, baris 1
  lcd.print("From Arducoding"); // Menampilkan pesan "From Arducoding" pada LCD
  delay(5000); // Jeda 5 detik
}
