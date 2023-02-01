#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi LCD
const int gasSensor = 7; // Pin sensor gas
const int flameSensor = 8; // Pin sensor api
const int buzzer = 9; // Pin buzzer
int gasValue, flameValue; // Variabel untuk menyimpan nilai gas dan api

void setup() {
  lcd.begin(); // Inisialisasi LCD
  lcd.backlight(); // Menyalakan backlight LCD
  pinMode(gasSensor, INPUT); // Konfigurasi pin sensor gas sebagai INPUT
  pinMode(flameSensor, INPUT); // Konfigurasi pin sensor api sebagai INPUT
  pinMode(buzzer, OUTPUT); // Konfigurasi pin buzzer sebagai OUTPUT
}

void loop() {
  gasValue = digitalRead(gasSensor); // Baca nilai gas
  flameValue = digitalRead(flameSensor); // Baca nilai api

  // Cek kondisi gas dan api
  if (gasValue >= 500 || flameValue >= 500) {
    // Tampilkan pesan pada LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Kebakaran Terdeteksi!");
    lcd.setCursor(0, 1);
    lcd.print("Tolong Segera Evakuasi");

    // Aktivasi buzzer
    tone(buzzer, 1000, 1000);
    delay(1000);
  } else {
    // Tampilkan pesan normal pada LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sistem Aman");
    lcd.setCursor(0, 1);
    lcd.print("Tidak Terdeteksi");

    // Matikan buzzer
    noTone(buzzer);
  }

  delay(500); // Delay selama 500 ms
}