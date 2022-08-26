#include <Joystick.h>
#include <Servo.h>

Servo servo;
int x = A1;
int y = A0;
Joystick joy(x, y);

void setup() {
  servo.attach(3);
  Serial.begin(9600);

}

void loop() {
  /*
   Function:
     get_direction()--> returns the x-coordinate
                        in terms of angle
                    --> at x-coordinate = 0, angle = 180
                    --> at x-coordinate = 1023, angle = 0
   Arguments:
     num_val = number of discrete values
     diff = difference between each values
     example:
       values of angle from 0-180 are divided into 10+1 discrete values
       angles = 0, 18, 36, 54, 72, 90, 108, 126, 144, 162, 180
       
       recommended:
          num_val = 10, diff = 18  --> has 10+1 discrete values incl. 0 and 180 (most stable, less buzz)
          
       other possible but inaccuracy is high due to rounding off:
          num_val = 20, diff = 9  --> has 20+1 discrete values incl. 0 and 180 
  
       needs to be integer to avoid the servo "buzz"
        
        
   */
  int angle = joy.get_direction(10, 18);
  Serial.println(angle);
  servo.write(angle);

}
