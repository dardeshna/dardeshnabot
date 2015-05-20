#include "Drivetrain.h"
#include "Constants.h"
#include <algorithm>
#include <iostream>

Drivetrain::Drivetrain():

	leftTopTalon((uint32_t) PORT_DRIVE_VIC_LEFT_FRONT),
	leftBottomTalon((uint32_t) PORT_DRIVE_VIC_LEFT_BACK),
	rightTopTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_FRONT),
	rightBottomTalon((uint32_t) PORT_DRIVE_VIC_RIGHT_BACK)
	
	{
		speed = 0;
		rotation = 0;
		state = IDLE;
		
	};
	
void Drivetrain::init() {
	speed = 0;
	rotation = 0;
	state = State::IDLE;
}

void Drivetrain::update() {
	switch (state) {
		case IDLE: {
			leftTopTalon.Set(0);
			leftBottomTalon.Set(0);
			rightTopTalon.Set(0);
			rightBottomTalon.Set(0);
			break;
		}
		case DRIVING: {
			leftTopTalon.Set(std::min(std::max(speed+rotation, -1.0), 1.0));
			leftBottomTalon.Set(std::min(std::max(speed+rotation, -1.0), 1.0));
			rightTopTalon.Set(std::min(std::max(speed-rotation, -1.0), 1.0));
			rightBottomTalon.Set(std::min(std::max(speed-rotation, -1.0), 1.0));
			
			if (speed == 0 && rotation == 0) {
			 state = State::IDLE;
			}
		}
	}
}

void Drivetrain::disable() {
	state = State::IDLE;
}

void Drivetrain::setSpeed(double speed, double rotation) {
	this -> speed = speed;
	this -> rotation = rotation;
	state = State::DRIVING;
}
