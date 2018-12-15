#include "Commands/Turn.h"
#include "iostream"
#include "math.h"
using namespace std;
Turn::Turn(double _setpoint) : setpoint(_setpoint) {
	Requires(Robot::drive);
	std::cout << "yee" << std::endl;
}

void Turn::Initialize() {
	//Calculates distance that the robot drives along its turning circle
	double diameter = 24;
	fDistance = fabs(M_PI*(diameter)*(setpoint/360));
	Robot::drive->resetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void Turn::Execute() {
	//turns either left or right depending on value passed
	if (setpoint > 0) {
		Robot::drive->tankDrive("Percent Output", -0.4, 0.4);//clockwise on red bobot
	} else {
	Robot::drive->tankDrive("Percent Output", 0.4, -0.4);//counterclockwise on red bobot
	}

}

bool Turn::IsFinished(){
	//Calculates remaining distance to the final distance
	double error = fDistance - (fabs(Robot::drive->leftDistance())+fabs(Robot::drive->rightDistance()))/2;
	
	//If the remaining distance is less than 1.3 in, end the turn
	return fabs(error) < 1.3; //.3
}

// Called once after isFinished returns true
void Turn::End() {
Robot::drive->resetEncoders();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Turn::Interrupted() {

}
