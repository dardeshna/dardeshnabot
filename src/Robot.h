#ifndef ROBOT_H
#define ROBOT_H

#include "Drivetrain.h"

class Robot {

	private:
	Drivetrain drivetrain;
	
	public:
	Robot();

	void init();
	void update();
	void disable();

	void move(double vertical, double horizontal);
	
};

#endif
