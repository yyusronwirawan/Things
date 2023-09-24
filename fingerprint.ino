#include <Adafruit_Fingerprint.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // Menggunakan SoftwareSerial untuk komunikasi dengan sensor sidik jari

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial); // Membuat objek sensor sidik jari

uint8_t id;

void setup()
{
  Serial.begin(9600);
  while (!Serial);  // Menunggu inisialisasi Serial Monitor
  delay(100);
  Serial.println("\nProses Enroll/Pendaftaran Sidik Jari");

  // Mengatur kecepatan komunikasi sensor sidik jari
  finger.begin(57600);

  // Memverifikasi kata sandi sensor sidik jari
  if (finger.verifyPassword()) {
    Serial.println("Sensor Fingerprint Terdeteksi!");
  } else {
    Serial.println("Sensor Fingerprint tidak terdeteksi :(");
    while (1) { delay(1); }
  }
}

uint8_t readnumber(void) {
  uint8_t num = 0;

  while (num == 0) {
    while (!Serial.available());
    num = Serial.parseInt(); // Membaca nomor dari Serial Monitor
  }
  return num;
}

void loop() // Diulang terus-menerus
{
  Serial.println("Pendaftaran Sidik Jari siap digunakan!");
  Serial.println("Masukan ID yang di pilih # (Dari 1 samapai 127)");
  Serial.println("\nAnda akan menyimpan sidik jari ini dengan ID...");
  id = readnumber(); // Membaca nomor ID dari Serial Monitor
  if (id == 0) {// ID #0 tidak diperbolehkan, coba lagi!
    return;
  }
  Serial.print("Enrolling ID #");
  Serial.println(id);

  while (!getFingerprintEnroll()); // Memulai proses pendaftaran sidik jari
}

uint8_t getFingerprintEnroll() {
  int p = -1;
  Serial.print("Waiting for valid finger to enroll as #"); Serial.println(id);
  while (p != FINGERPRINT_OK) {
    p = finger.getImage(); // Mengambil gambar sidik jari
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // Gambar sidik jari telah diambil

  p = finger.image2Tz(1); // Konversi gambar menjadi template sidik jari
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  Serial.println("Remove finger");
  delay(2000); // Tunggu selama 2 detik agar pengguna mengangkat jari mereka
  p = 0;
  while (p != FINGERPRINT_NOFINGER) {
    p = finger.getImage();
  }
  Serial.print("ID "); Serial.println(id);
  p = -1;
  Serial.println("Tempatkan jari yang sama lagi!");
  while (p != FINGERPRINT_OK) {
    p = finger.getImage();
    switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.print(".");
      break;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      break;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      break;
    default:
      Serial.println("Unknown error");
      break;
    }
  }

  // Gambar sidik jari kedua telah diambil

  p = finger.image2Tz(2); // Konversi gambar kedua menjadi template sidik jari
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // Template sidik jari kedua telah dibuat

  Serial.print("Creating model for #");  Serial.println(id);

  p = finger.createModel(); // Membuat model sidik jari
  if (p == FINGERPRINT_OK) {
    Serial.println("Fingerprint Sesuai!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Komunikasi error");
    return p;
  } else if (p == FINGERPRINT_ENROLLMISMATCH) {
    Serial.println("Fingerprints tidak sesuai");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }

  Serial.print("ID "); Serial.println(id);
  p = finger.storeModel(id); // Menyimpan model sidik jari ke dalam sensor
  if (p == FINGERPRINT_OK) {
    Serial.println("Tersimpan!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Komunikasi error");
    return p;
  } else if (p == FINGERPRINT_BADLOCATION) {
    Serial.println("Tidak bisa menyimpan di penyimpanan.");
    return p;
  } else if (p == FINGERPRINT_FLASHERR) {
    Serial.println("Error writing to flash");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }
}
