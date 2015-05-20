#ifndef DRIVETRAIN_H
#define DRIVETRAIN_H

#include <WPILib.h>

class Drivetrain {
	
	private:
	TalonSRX leftTopTalon;
	TalonSRX leftBottomTalon;
	TalonSRX rightTopTalon;
	TalonSRX rightBottomTalon;
	
	double speed;
	double rotation;

	public:
	Drivetrain();
	
	void init();
	void update();
	void disable();
	
	typedef enum State {
		IDLE,
		DRIVING
	} State;
	State state;
	
	void setSpeed(double speed, double rotation);
	
};

#endif
