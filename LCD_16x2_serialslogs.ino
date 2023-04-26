#include <LiquidCrystal.h>
#include <SPI.h>

float temperature, humidity;

LiquidCrystal Screen16x2(7, 8, 9, 3, 5 , 6);

void setup() {
    Screen16x2.begin(16, 2);
    Serial.begin(9600);
    randomSeed(1001);

}

void loop() {

  temperature = 29.7 + random(-1.9, 2.0);
  humidity = 60.7 + + random(-5.1, 5.2);
  String stemp = String(temperature);
  String shum = String(humidity);
  printLCD(0, 0, stemp + "C");
  printLCD(8, 0, shum + "%");
  delay(250);
  
}
  
void printLCD(int col, int row, String Value) {
    Screen16x2.setCursor(col, row);
    Screen16x2.write(Value.c_str());
}
