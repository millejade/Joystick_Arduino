#pragma once
#include "Arduino.h"
#define MAX 1023


class Joystick{
public:
	int pinX, pinY;

public:
	Joystick(int x, int y);
	int get_x(); // get the x-coordinate of the joystick
	int get_y(); // get the y-coordinate of the joystick
	void get_coor(int (&coor)[2]); // get the x- and y-coordinate of the joystick (need to spec)
	int get_change_speed();  // used to control the motor speed
	int get_change_direction();
	int get_direction(int num_val, int diff); // used to control the servo motor

private:
	void read_speed(float&);
	void read_direction(float&);
	void accelerate_speed(int& change_in_speed, float& speed);
	void deccelerate_speed(int& change_in_speed, float& speed);
	void move_right(int& change_in_direction, float& direction);
	void move_left(int& change_in_direction, float& direction);

};


