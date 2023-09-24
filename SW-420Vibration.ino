int LED_Pin = D1;    // Mendefinisikan pin D1 sebagai pin untuk LED
int vibr_Pin = D3;   // Mendefinisikan pin D3 sebagai pin untuk sensor getaran

void setup() {
  pinMode(LED_Pin, OUTPUT);  // Mengatur pin LED_Pin sebagai output
  pinMode(vibr_Pin, INPUT);  // Mengatur pin vibr_Pin sebagai input untuk pengukuran
  Serial.begin(9600);        // Memulai komunikasi serial dengan kecepatan 9600 bps
}

void loop() {
  long measurement = TP_init();  // Memanggil fungsi TP_init() untuk mengukur getaran
  delay(50);                     // Menunggu selama 50 milidetik
  Serial.println(measurement);   // Mencetak hasil pengukuran ke Serial Monitor

  if (measurement > 1000) {     // Memeriksa hasil pengukuran
    digitalWrite(LED_Pin, HIGH);  // Mengaktifkan LED jika getaran melebihi 1000
  } else {
    digitalWrite(LED_Pin, LOW);   // Mematikan LED jika getaran kurang dari 1000
  }
}

long TP_init() {
  delay(10);                     // Jeda 10 milidetik
  long measurement = pulseIn(vibr_Pin, HIGH);  // Mengukur getaran dan mengembalikan hasil pengukuran
  return measurement;            // Mengembalikan nilai hasil pengukuran
}
