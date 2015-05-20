#include "HumanController.h"
#include "Constants.h"

HumanController::HumanController(Robot *robot):
moveStick((uint32_t) PORT_MOVESTICK), turnStick((uint32_t) PORT_TURNSTICK), robot(robot)
{
}

void HumanController::update() {
	robot->move(moveStick.GetY(), turnStick.GetX());
}
