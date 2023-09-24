#include <ESP8266.h>
#include <Wire.h>

const int LM2596_ADJ_PIN = D1;  // Pin NodeMCU yang terhubung ke pin ADJ modul LM2596

void setup() {
  Serial.begin(9600);
  pinMode(LM2596_ADJ_PIN, OUTPUT);
  analogWrite(LM2596_ADJ_PIN, 0);  // Nilai PWM awal (0-1023)
}

void loop() {
  // Baca input dari penggunaan Serial Monitor
  if (Serial.available() > 0) {
    int inputValue = Serial.parseInt();
    if (inputValue >= 0 && inputValue <= 1023) {
      analogWrite(LM2596_ADJ_PIN, inputValue);
      Serial.print("Tegangan keluaran diatur ke: ");
      Serial.println(map(inputValue, 0, 1023, 0, 3300) / 1000.0, 2); // Konversi ke tegangan dalam volt
    } else {
      Serial.println("Masukkan nilai antara 0 hingga 1023");
    }
  }
}
