//#include <Utilities/AutoWVPIDController.h>
#pragma once
#include <Commands/Command.h>
#include "Robot.h"
class Turn : public Command {
	public:
	Turn(double _setpoint);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double setpoint;
	double error;
	double fDistance;
};


