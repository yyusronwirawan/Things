#include <Servo.h>  // Mengimpor pustaka Servo

Servo servoKu;  // Membuat objek Servo bernama servoKu

void setup() {
  servoKu.attach(D4);  // Menghubungkan servo ke pin D4
}

void loop() {
  servoKu.write(90);   // Memutar servo ke posisi sudut 90 derajat
  delay(1000);         // Menunda selama 1 detik (1000 milidetik)
  servoKu.write(180);  // Memutar servo ke posisi sudut 180 derajat
  delay(1000);         // Menunda selama 1 detik (1000 milidetik)
}
