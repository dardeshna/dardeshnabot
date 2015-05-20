#include <WPILib.h>
#include "Robot.h"
#include "HumanController.h"

class TestRobot: public IterativeRobot {

private:
	Robot robot;
	HumanController humanController;

public:
	TestRobot();
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};

TestRobot::TestRobot(): robot(), humanController(&robot) {
}

void TestRobot::RobotInit() {
	robot.init();
}

void TestRobot::DisabledInit() {
	robot.disable();
}

void TestRobot::DisabledPeriodic() {
	robot.disable();
	robot.update();
}

void TestRobot::TeleopInit() {
	robot.init();
}

void TestRobot::TeleopPeriodic() {
	humanController.update();
	robot.update();
}

START_ROBOT_CLASS(TestRobot);
