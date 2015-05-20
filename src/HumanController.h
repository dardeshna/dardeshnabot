#include <WPILib.h>
#include "Robot.h"

class HumanController {
	private:
		Joystick moveStick;
		Joystick turnStick;

		Robot *robot;
		
	public:
		HumanController(Robot *robot);
		
		void init();
		void update();
		void disable();
};
