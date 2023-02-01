#include <Servo.h> // import library Servo

// deklarasikan pin servo dan pin sensor sidik jari
const int servoPin = 9;
const int sensorPin = 2;

Servo myServo; // deklarasikan variabel servo

void setup() {
  myServo.attach(servoPin); // pasang servo pada pin servo
  pinMode(sensorPin, INPUT); // set sensorPin sebagai INPUT
  Serial.begin(9600); // set baud rate ke 9600
}

void loop() {
  // baca nilai dari sensorPin
  int sensorValue = digitalRead(sensorPin);
  if (sensorValue == LOW) { // jika sensor mengeluarkan sinyal LOW
    Serial.println("Sidik jari dikenali. Membuka pintu...");
    myServo.write(90); // buka pintu dengan menggerakkan servo
    delay(1000); // tunggu selama 1 detik
    myServo.write(0); // tutup pintu dengan menggerakkan servo kembali ke posisi awal
  }
  else { // jika sensor tidak mengeluarkan sinyal LOW
    Serial.println("Sidik jari tidak dikenali. Pintu tetap tertutup.");
  }
}