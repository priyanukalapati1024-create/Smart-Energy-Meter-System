/*
  Task 6 - Smart Energy Meter System
  Slashmark LMS | ADVANCED Project
  Sensor: ACS712 5A, Board: Arduino Uno
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int currentPin = A0;
const float voltage = 230.0; // India standard AC voltage
float current = 0;
float power = 0;
float energy = 0;
unsigned long lastTime = 0;

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Smart Energy");
  lcd.setCursor(0,1);
  lcd.print("Meter System");
  delay(2000);
  lcd.clear();
  Serial.println("Time(s),Current(A),Power(W),Energy(kWh)");
}

void loop() {
  // Read ACS712 sensor - 5A module
  int sensorValue = analogRead(currentPin);
  float voltage_read = (sensorValue / 1024.0) * 5000; // mV
  current = (voltage_read - 2500) / 185.0; // 5A module: 185mV/A
  if(current < 0.10) current = 0; // Remove noise
  
  power = voltage * abs(current); // P = V * I
  
  // Calculate energy kWh
  unsigned long currentTime = millis();
  float timeHours = (currentTime - lastTime) / 3600000.0; // ms to hours
  energy += (power * timeHours) / 1000.0; // kWh
  lastTime = currentTime;
  
  // Serial Monitor - for storage/analysis
  Serial.print(millis()/1000); Serial.print(",");
  Serial.print(abs(current),2); Serial.print(",");
  Serial.print(power,2); Serial.print(",");
  Serial.println(energy,4);
  
  // LCD Display
  lcd.setCursor(0,0);
  lcd.print("P:"); lcd.print(power,1); lcd.print("W ");
  lcd.print("I:"); lcd.print(abs(current),1); lcd.print("A");
  
  lcd.setCursor(0,1);
  lcd.print("Energy:");
  lcd.print(energy,3); lcd.print("kWh");
  
  delay(2000);
}
