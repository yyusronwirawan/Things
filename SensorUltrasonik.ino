// Mendefinisikan pin trigger sebagai D8 dan pin echo sebagai D7
#define triggerPin  D8
#define echoPin     D7

void setup() {
  // Memulai komunikasi serial dengan kecepatan 9600 bps
  Serial.begin (9600);

  // Mengatur pin trigger sebagai output (untuk mengirim sinyal ultrasonik)
  pinMode(triggerPin, OUTPUT);

  // Mengatur pin echo sebagai input (untuk menerima pantulan sinyal ultrasonik)
  pinMode(echoPin, INPUT);
}

void loop() {
  long duration, jarak;

  // Mematikan sinyal trigger
  digitalWrite(triggerPin, LOW);

  // Menunda selama 2 mikrodetik
  delayMicroseconds(2); 

  // Mengaktifkan sinyal trigger dengan mengirimkan sinyal HIGH selama 10 mikrodetik
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10); 

  // Mematikan kembali sinyal trigger
  digitalWrite(triggerPin, LOW);

  // Membaca durasi atau waktu yang diperlukan untuk menerima pantulan sinyal ultrasonik
  duration = pulseIn(echoPin, HIGH);

  // Menghitung jarak berdasarkan durasi yang diukur
  jarak = (duration / 2) / 29.1;

  // Mencetak pesan "jarak :" ke Serial Monitor
  Serial.println("jarak :");

  // Mencetak nilai jarak ke Serial Monitor
  Serial.print(jarak);

  // Mencetak pesan " cm" ke Serial Monitor
  Serial.println(" cm");

  // Jeda 1 detik sebelum membaca sensor lagi
  delay(1000);
}
