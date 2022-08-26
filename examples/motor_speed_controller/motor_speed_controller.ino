#include <Joystick.h>

// Initialize the pins
int x = A1;
int y = A0;
int motor_pin = 6;
float motor_speed = 0.0;
const float quicky = 0.2;
Joystick joy(x, y); // create an instance

void setup() {
  pinMode(motor_pin, OUTPUT);
  Serial.begin(9600);

}

void loop() {

 /*
  Function:
      get_change_speed() --> returns a positive/negative value
          if y-coordinate value of joystick increases, the speed will also increases
          if y-coordinate value of joystick decreases, the speed will also decrease
          if y-coordinate of joystick remains at the center, then there will be no change in speed

          adjust "quicky" to increase/decrease how quick it will accelerates/deccelerates
            increasing the quicky will increase how quick the motor will accelerate/deccelerate
            decreasing it will then decrease how quick the motor will accelerate/deccelerate
            *at quicky = 0.075, the time it will take to reach 255 from 0 is approx. 3.6s
            *at quicky = 0.1, the time it will take to reach 255 from 0 is approx. 3.4s
            *at quicky = 0.2, the time it will take to reach 255 from 0 is approx. 1.57s
                time here might change depending on the computer or if you have other process/statement inside the loop or if there's a delay
  */
  float accelerator = joy.get_change_speed() * quicky;
  motor_speed += accelerator;
  
  if(motor_speed <= 0.0){
    motor_speed = 0;
  }else if(motor_speed >= 255.0){
    motor_speed = 255;
  }
  
  Serial.println(int(motor_speed));
  analogWrite(motor_pin, int(motor_speed));

}
