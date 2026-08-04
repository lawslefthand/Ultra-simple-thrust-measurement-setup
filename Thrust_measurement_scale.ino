#include "HX711.h"

#define DT 2
#define CLK 3

#define calibration_factor 131.55  
char incomingChar = 0; 


HX711 scale;

void setup() {
  Serial.begin(9600);
  Serial.println("Thrust Measurement Scale");
  delay(300);
  Serial.println("Starting initial TAR");

  scale.begin(DT, CLK);

  scale.set_scale(calibration_factor);
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  delay(300);
  Serial.println("Good to go!");
  delay(300);

}

void loop() {
  //Serial.print("Reading: ");
  Serial.print(scale.get_units(), 1);
  Serial.print(" gm");
  Serial.println();
  

    incomingChar = Serial.read(); 
    if (incomingChar == 't' || incomingChar == 'T')
    {
      Serial.print("Tarring, hold on.");
      scale.set_scale(calibration_factor);
      scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
      delay(300);
      Serial.println("Good to go lads!");
      delay(300);
    }
    


  delay(100);
}