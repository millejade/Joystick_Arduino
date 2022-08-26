#include "Joystick.h"


Joystick::Joystick(int x, int y){
	pinX = x;
	pinY = y;
}

int Joystick::get_x(){
	int x_val = analogRead(pinX);
	return x_val;
}

int Joystick::get_y(){
	int y_val = analogRead(pinY);
	return y_val;
}

void Joystick::get_coor(int (&coor)[2]){
    coor[0] = Joystick::get_x();
    coor[1] = Joystick::get_y();
}

void Joystick::read_speed(float& speed){
	speed = Joystick::get_y() / 1023.0f;
}

void Joystick::read_direction(float& direction){
	direction = Joystick::get_x() / 1023.0f;
}

void Joystick::accelerate_speed(int& change_in_speed, float& speed){
	change_in_speed = int((1/(1.1 - speed)*0.5));
}

void Joystick::deccelerate_speed(int& change_in_speed, float& speed){
	change_in_speed = int((1/(-0.1-speed)*0.5));
}

void Joystick::move_right(int& change_in_direction, float& direction){
	change_in_direction = int(-1*(1/(3*(1.1 - direction))));
}

void Joystick::move_left(int& change_in_direction, float& direction){
	change_in_direction = int(1/(3*(0.1 + direction)));
}

int Joystick::get_change_speed(){
	int change_in_speed = 0;
	float speed;
	Joystick::read_speed(speed);
	if(speed > 0.485 && speed < 0.515){
		return change_in_speed;
	}else if(speed >= 0.515){
		Joystick::accelerate_speed(change_in_speed, speed);
		return change_in_speed;
	}else if(speed <= 0.485){
		Joystick::deccelerate_speed(change_in_speed, speed);
		return change_in_speed;
	}
}

int Joystick::get_change_direction(){
	int change_in_direction = 0;
	float direction;
	Joystick::read_direction(direction);
	if(direction > 0.485 && direction < 0.515){
		return 0;
	}else if(direction >= 0.515){
		Joystick::move_right(change_in_direction, direction);
		return change_in_direction;
	}else if(direction <= 0.485){
		Joystick::move_left(change_in_direction, direction);
		return change_in_direction;
	}
}

int Joystick::get_direction(int num_val, int diff){
	float direction;
	Joystick::read_direction(direction);
	int angle = round(direction * num_val) * diff;
	angle = abs(angle - 180);
	return angle;

}






