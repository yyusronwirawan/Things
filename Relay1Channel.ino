#define LED  D1 // PIN RELAY
void setup() {
  // put your setup code here, to run once:
pinMode(Relay,OUTPUT);   \\menentukan Relay Sebagai Output
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Relay,HIGH);     \\Menyalakan relay
delay(1000);                  \\ Jeda 1 Detik
digitalWrite(Relay,LOW);      \\ Mematikan Relay
}