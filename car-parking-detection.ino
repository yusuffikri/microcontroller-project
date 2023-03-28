// Library untuk sensor ultrasonik
#include <NewPing.h>

// Pin untuk sensor ultrasonik
#define TRIGGER_PIN  12  // Pin trigger
#define ECHO_PIN     11  // Pin echo
#define MAX_DISTANCE 200 // Jarak maksimal (cm)

// Inisialisasi sensor ultrasonik
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

// Pin untuk pintu gerbang
const int gatePin = 9;

void setup() {
  // Konfigurasi pin pintu gerbang sebagai output
  pinMode(gatePin, OUTPUT);
  
  // Serial monitor
  Serial.begin(9600);
}

void loop() {
  // Mengukur jarak menggunakan sensor ultrasonik
  int distance = sonar.ping_cm();
  
  // Jika kendaraan terdeteksi
  if (distance < 20) {
    // Buka pintu gerbang
    digitalWrite(gatePin, HIGH);
    Serial.println("Pintu gerbang terbuka");
    delay(5000); // Tunggu 5 detik
    
    // Tutup pintu gerbang
    digitalWrite(gatePin, LOW);
    Serial.println("Pintu gerbang tertutup");
  }
  
  // Delay untuk mencegah loop terlalu cepat
  delay(500);
}
