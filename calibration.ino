#include "HX711.h"

#define DT 2
#define CLK 3

HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("HX711 calibration sketch");

  scale.begin(DT, CLK);
}

void loop() {
  scale.set_scale();
  Serial.println("");
  Serial.println("Remove all weight from scale");
  delay(5000);
  scale.tare();
  Serial.println("Tare done!");

  Serial.println("Place a known weight on the scale...");
  delay(5000);
  long reading = scale.get_units(10);
  Serial.print("Reading: ");
  Serial.println(reading);
  delay(1000);
}
