#include "HX711.h"
#include "EasyNextionLibrary.h"  // Include EasyNextionLibrary

using namespace std;
char incoming;


EasyNex myNex(Serial); // Create an object of EasyNex class with the name < myNex >
                       // Set as parameter the Hardware Serial you are going to use

#define DT 2
#define CLK 3

#define calibration_factor 131.55  
char incomingChar = 0; 
volatile int unit_flag = 0;


HX711 scale;

void setup() {
  Serial.begin(9600);
 // Serial.println("Thrust Measurement Scale");
  delay(300);
  //Serial.println("Starting initial TAR");

  scale.begin(DT, CLK);

  scale.set_scale(calibration_factor);
  scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0

  delay(300);
  //Serial.println("Good to go!");
  delay(300);

}

void loop() {
  //Serial.print("Reading: ");
 // Serial.print(scale.get_units(), 1);
 // Serial.print(" gm");
 // Serial.println();



  float bruh = scale.get_units();

  if (unit_flag == 0)
  {
    bruh = bruh; // literally the same and not needed but i'm kinda crazy
  }
  if (unit_flag == 1)
  {
    bruh = bruh/1000.0;
  }
  if (unit_flag == 2)
  {
    bruh = bruh/ 453.59;
  }
  myNex.writeStr("t4.txt", String(bruh)); // The text in t0 is now this

  incoming = Serial.read();
 
  
   // Serial.print( Serial.readString());
    if (incoming == 'A')
    {
      scale.set_scale(calibration_factor);
      scale.tare();  //Assuming there is no weight on the scale at start up, reset the scale to 0
      delay(300);
      
    }

    if (incoming == '0')
    {
      unit_flag++;
      if (unit_flag > 2)
      {
        unit_flag = 0;
      }
      
      
      
    }

 incoming = 'm';
    
  delay(100);
}
