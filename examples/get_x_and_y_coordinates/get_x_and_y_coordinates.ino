#include <Joystick.h>

// Initialize the pins
int x = A1;
int y = A0;

int x_coor = 0;
int y_coor = 0;
Joystick joy(x, y); // create an instance

void setup() {
  Serial.begin(9600);

}

void loop() {
  /*
   Functions: 
   get_x() --> returns a value from 0 to 1023
   get_y() --> returns a value from 0 to 1023
   */
  x_coor = joy.get_x();
  y_coor = joy.get_y();
  Serial.print("x: ");
  Serial.print(x_coor);
  Serial.print(",     ");
  Serial.print("y: ");
  Serial.println(y_coor);

}
