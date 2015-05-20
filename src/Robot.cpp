#include "Robot.h"

Robot::Robot(): drivetrain()
{

}

void Robot::init() {
	drivetrain.init();
}
void Robot::update() {
	drivetrain.update();
}
void Robot::disable() {
	drivetrain.disable();
}

void Robot::move(double vertical, double horizontal) {
	drivetrain.setSpeed(vertical, horizontal);
}
