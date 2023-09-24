#include <SPI.h>            // Mengimpor pustaka SPI untuk komunikasi dengan perangkat RFID.
#include <RFID.h>           // Mengimpor pustaka RFID untuk mengelola perangkat RFID.
#define SDA_PIN D2          // Mendefinisikan pin SDA (Data) yang digunakan untuk komunikasi SPI.
#define RST_PIN D1           // Mendefinisikan pin RST (Reset) yang digunakan untuk mengatur ulang perangkat RFID.
RFID rfid(SDA_PIN, RST_PIN);  // Membuat objek RFID dengan pin SDA dan RST yang telah ditentukan.

int serNum[5];              // Variabel untuk menyimpan data nomor seri kartu.

void setup()
{
  Serial.begin(9600);       // Memulai komunikasi serial dengan baud rate 9600.
  SPI.begin();              // Memulai komunikasi SPI.
  rfid.init();              // Memulai perangkat RFID.
  delay(1000);              // Menunda eksekusi program selama 1 detik.
  Serial.println("Sistem Pembacaan E-KTP Ready..."); // Pesan status sistem siap.
  delay(2000);              // Menunda eksekusi program selama 2 detik.
  Serial.println("Tempelkan E-KTP Anda");          // Pesan instruksi kepada pengguna.
  Serial.println("");       // Baris kosong untuk pemisah.
}

void loop()
{
  if (rfid.isCard())        // Memeriksa apakah ada kartu dalam jangkauan.
  {
    if (rfid.readCardSerial()) // Membaca nomor seri kartu jika kartu terdeteksi.
    {
      Serial.print("Kode Tag E-KTP"); // Pesan label untuk nomor seri kartu.
      Serial.print(" : ");
      Serial.print(rfid.serNum[0]);   // Mencetak setiap digit nomor seri kartu.
      Serial.print(" ");
      Serial.print(rfid.serNum[1]);
      Serial.print(" ");
      Serial.print(rfid.serNum[2]);
      Serial.print(" ");
      Serial.print(rfid.serNum[3]);
      Serial.print(" ");
      Serial.print(rfid.serNum[4]);
      Serial.println("");  // Baris kosong untuk pemisah.
    }
  }
  rfid.halt();              // Menonaktifkan komunikasi dengan kartu RFID.
  delay(1000);              // Menunda eksekusi program selama 1 detik sebelum membaca kartu berikutnya.
}
