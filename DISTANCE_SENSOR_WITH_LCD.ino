#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <NewPing.h>

#define I2C_ADDR 0x27
#define totalRows 2
#define totalColumns 16

LiquidCrystal_I2C lcd(I2C_ADDR, totalColumns, totalRows);
#define trigger 16
#define echo 17

NewPing sonar(trigger, echo);

void setup() {
  lcd.init();
  lcd.backlight();
}

void loop() {
  unsigned int distance = sonar.ping_cm();
  Serial.print("UZAKLIK= ");
  Serial.print(distance);
  Serial.println(" cm");

  lcd.setCursor(0, 0);
  lcd.print("UZAKLIK= ");
  lcd.print(distance);
  lcd.print(" cm");

  delay(2000);

  lcd.clear();
}
