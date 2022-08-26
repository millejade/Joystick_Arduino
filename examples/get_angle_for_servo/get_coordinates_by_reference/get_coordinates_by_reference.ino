#include <Joystick.h>

// Initialize the pins
int x = A1;
int y = A0;

int coordinates[2];
Joystick joy(x, y); // create an instance

void setup() {
  Serial.begin(9600);

}

void loop() {
  /*
   Function:
   get_coor(array)
        >> must pass an array as argument
        >> array must have a length of two (2)
        >> array[0] indicates x-coordinate
        >> array[1] indicates y-coordinate
        - What it does is you're passing the
          array and change/modify the value of
          it through Joystick library.
   */

  joy.get_coor(coordinates);
  Serial.print("x: ");
  Serial.print(coordinates[0]);
  Serial.print(",     ");
  Serial.print("y: ");
  Serial.println(coordinates[1]);
  

}
