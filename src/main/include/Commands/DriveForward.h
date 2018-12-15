#pragma once


#include <Commands/Command.h>
#include "Robot.h"
class DriveForward : public Command {
private:
	double setpoint;
	double position_avg;
	double velocity;
	double time1;
	double time2;
public:
	DriveForward(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void setAngle();
};


