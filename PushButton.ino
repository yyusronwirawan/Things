#define pinLED D1      // Mendefinisikan pin LED sebagai D1
#define pinButton D2   // Mendefinisikan pin tombol sebagai D2

int buttonState;      // Variabel untuk menyimpan status tombol
int oldButton = 0;    // Variabel untuk menyimpan status tombol sebelumnya
int state = 0;        // Variabel untuk menyimpan status LED

void setup() {
  Serial.begin(9600);  // Memulai komunikasi serial dengan kecepatan 9600 bps
  pinMode(pinLED, OUTPUT);       // Mengatur pin LED sebagai OUTPUT
  pinMode(pinButton, INPUT_PULLUP); // Mengatur pin tombol sebagai INPUT dengan pull-up internal
}

void loop() {
  buttonState = digitalRead(pinButton); // Membaca status tombol

  // Memeriksa apakah tombol ditekan (LOW) dan sebelumnya tidak ditekan
  if (!buttonState && !oldButton) {
    if (state == 0) {
      digitalWrite(pinLED, HIGH);  // Menyalakan LED
      Serial.println("LED ON");
      state = 1;
    } else {
      digitalWrite(pinLED, LOW);   // Mematikan LED
      Serial.println("LED OFF");
      state = 0;
    }
    oldButton = 1;  // Menandai bahwa tombol telah ditekan
  } else if (buttonState && oldButton) {
    oldButton = 0;  // Menandai bahwa tombol dilepas
  }
}
