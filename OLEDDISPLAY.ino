#include <SPI.h>              // Library SPI
#include <Wire.h>             // Library Wire
#include <Adafruit_GFX.h>     // Library GFX
#include <Adafruit_SSD1306.h> // Library OLED SSD1306

#define SCREEN_WIDTH 128 // Panjang LCD OLED
#define SCREEN_HEIGHT 64 // Tinggi LCD OLED

#define OLED_RESET -1    // Pin reset terhubung dengan Arduino
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(9600);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Alamat OLED
    Serial.println(F("SSD1306 allocation failed"));
    for (;;); // Don't proceed, loop forever
  }
}

void loop() {
  // display.display();
  // delay(2000);
  display.clearDisplay();
  display.setTextSize(1);          // Instruksi mengatur ukuran karakter
  display.setTextColor(WHITE);     // Instruksi untuk mengatur warna
  display.setCursor(32, 0);       // Karakter dimulai dari kolom 32 baris 0
  display.print("Welcome to");     // Menampilkan karakter "Welcome to" pada OLED
  display.setTextSize(1);          // Instruksi mengatur ukuran karakter
  display.setCursor(20, 10);       // Karakter dimulai dari kolom 20 baris 10
  display.setTextColor(WHITE);     // Instruksi untuk mengatur warna tampilan
  display.println("Indomaker.com"); // Menampilkan karakter "Indomaker.com" pada OLED
  display.setTextSize(1);          // Instruksi mengatur ukuran karakter
  display.setCursor(10, 20);
  display.setTextColor(WHITE);
  display.print("Innovate Every day"); // Menampilkan karakter "Innovate Every Day" pada OLED
  display.display();
  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);          // Instruksi mengatur ukuran karakter
  display.setTextColor(WHITE);     // Instruksi untuk mengatur warna
  display.setCursor(20, 0);       // Karakter dimulai dari kolom 20 baris 0
  display.print("Tutorial");       // Menampilkan karakter "Tutorial" pada OLED
  display.setTextSize(2);          // Instruksi mengatur ukuran karakter
  display.setTextColor(WHITE);     // Instruksi untuk mengatur warna
  display.setCursor(40, 20);      // Karakter dimulai dari kolom 40 baris 20
  display.print("OLED");           // Menampilkan karakter "OLED" pada OLED
  display.setTextSize(2);          // Instruksi mengatur ukuran karakter
  display.setCursor(20, 50);      // Karakter dimulai dari kolom 20 baris 50
  display.setTextColor(WHITE);     // Instruksi untuk mengatur warna tampilan
  display.println("SSD1306");      // Menampilkan karakter "SSD1306" pada OLED
  display.display();
  delay(2000);
}
