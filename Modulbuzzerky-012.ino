int speakerPin = D8;  // Mendefinisikan pin untuk speaker sebagai D8

void setup () {
  pinMode (speakerPin, OUTPUT);  // Mengatur pin speaker sebagai output
}

void loop () {
  analogWrite (speakerPin, 255);  // Mengirimkan sinyal PWM penuh ke speaker
  delay (50);                      // Menunda selama 50 milidetik (0.05 detik)
  analogWrite (speakerPin, 0);    // Mematikan suara dengan mengirimkan sinyal PWM 0
  delay (10);                      // Menunda selama 10 milidetik (0.01 detik)
}
