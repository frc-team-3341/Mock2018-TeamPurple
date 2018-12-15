/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems/DriveTrain.h"
#include "Commands/TankDrive.h"
#include "Commands/ArcadeDrive.h"
#include "iostream"

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem"), left(new TalonSRX(2)), right(new TalonSRX(3)) 
{

  int kPIDLoopIdx = 0;
	int kTimeoutMs = 30;

	left->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	left->SetSensorPhase(true);
	//left->SetStatusFramePeriod(StatusFrameEnhanced.Status_10_MotionMagic,10,kTimeoutMs)
	//left->SetStatusFramePeriod(StatusFrameEnhanced.Status_13_base_PIDF0,10,kTimeoutMs);

	left->ConfigNominalOutputForward(0, kTimeoutMs);
	left->ConfigNominalOutputReverse(0, kTimeoutMs);
	left->ConfigPeakOutputForward(1, kTimeoutMs);
	left->ConfigPeakOutputReverse(-1, kTimeoutMs);

	left->Config_kF(kPIDLoopIdx, 0.1097, kTimeoutMs);
	left->Config_kP(kPIDLoopIdx, 0.22, kTimeoutMs);
	left->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	left->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

	// left->ConfigEncoderCodesPerRev(360);
	left->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms,0);
	left->ConfigVelocityMeasurementWindow(64,0);
	left->SetSelectedSensorPosition(0,0,10);

	left->Set(ControlMode::Position, 0);

	left->ConfigMotionCruiseVelocity(15000, kTimeoutMs);
	left->ConfigMotionAcceleration(6000, kTimeoutMs);

	right->ConfigSelectedFeedbackSensor(FeedbackDevice::CTRE_MagEncoder_Relative,0,10);
	right->ConfigVelocityMeasurementPeriod(VelocityMeasPeriod::Period_10Ms,0);
	right->ConfigVelocityMeasurementWindow(64,0);
	// right->ConfigEncoderCodesPerRev(360);
	right->SetSelectedSensorPosition(0,0,10);
	right->SetSensorPhase(true);
	right->Set(ControlMode::Position, 0);

	right->ConfigNominalOutputForward(0, kTimeoutMs);
	right->ConfigNominalOutputReverse(0, kTimeoutMs);
	right->ConfigPeakOutputForward(1, kTimeoutMs);
	right->ConfigPeakOutputReverse(-1, kTimeoutMs);

	right->Config_kF(kPIDLoopIdx, 0.1097, kTimeoutMs);
	right->Config_kP(kPIDLoopIdx, 0.22, kTimeoutMs);
	right->Config_kI(kPIDLoopIdx, 0.0, kTimeoutMs);
	right->Config_kD(kPIDLoopIdx, 0.0, kTimeoutMs);

	right->ConfigMotionCruiseVelocity(15000, kTimeoutMs);
	right->ConfigMotionAcceleration(6000, kTimeoutMs);

  std::cout << "help" << std::endl;
  left->SetInverted(true);
  right->SetInverted(false);

  
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
 SetDefaultCommand(new TankDrive());
 //SetDefaultCommand(new ArcadeDrive());

}

void DriveTrain::tankDrive(double leftPower, double rightPower)
{
  left->Set(ControlMode::PercentOutput, leftPower);
  right->Set(ControlMode::PercentOutput, rightPower);
}


void DriveTrain::tankDrive(std::string s, double leftVal, double rightVal) {

	if (s == "magic"){
		//Motion Magic
		left->Set(ControlMode::MotionMagic, leftVal*4096/circumference); //Convert inches to ticks
		right->Set(ControlMode::MotionMagic, rightVal*4096/circumference);
	}
	else{
		//Percent Output
		left->Set(ControlMode::PercentOutput, DriveTrain::Limit(leftVal, 1));
		right->Set(ControlMode::PercentOutput, DriveTrain::Limit(rightVal, 1));
	}
	//cout << "left: " << leftVal << "  right: " << rightVal << endl;
}

RobotDrive* DriveTrain::getChassis()
{
  return chassis;
}
// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::invertMotors()
{
  
  
    left->SetInverted(!left->GetInverted());
    right->SetInverted(!right->GetInverted());
}


void DriveTrain::resetEncoders()
{
	left->SetSelectedSensorPosition(0,0,10);
	right->SetSelectedSensorPosition(0,0,10);
	left->Set(ControlMode::Position, 0);
	right->Set(ControlMode::Position, 0);
}

/* DriveTrain::setStartAbsTicks(){
	startAbsTicks = left->GetSensorCollection().GetPulseWidthPosition();
	cout << "Start: " << startAbsTicks << endl;
}*/

double DriveTrain::leftDistance()
 { //inches

	//double test = left->GetSensorCollection().GetPulseWidthPosition();
	double relativePosition = left->GetSensorCollection().GetQuadraturePosition(); // Return ticks

	relativePosition = ((relativePosition) / 4096) * circumference; // 4096 ticks per revolution
	//cout << "Abs: " << test << endl;
	//test = ((test)/ 4096) * circumference;

	//cout << "Start: " << startAbsTicks << endl;
	//cout<< "Relative Position: " << relativePosition <<std::endl;
	//cout<< "Absolute Position: " << test <<std::endl;

	return relativePosition;
}

double DriveTrain::rightDistance() { //inches

	// double relativePosition = (double) (right->GetSensorCollection().GetPulseWidthPosition()); This also works, but I don't know what is different
	double relativePosition = -(right->GetSensorCollection().GetQuadraturePosition()); // Negative sign makes sure that forwards is positive and backwards is negative
	relativePosition = (relativePosition / 4096) * circumference; // 4096 ticks per revolution
	// std::cout<< "Right Wheel Relative Position: " << relativePosition << std::endl;
	return relativePosition;


}

double DriveTrain::getSpeed(){
	return ((left->GetSensorCollection().GetPulseWidthVelocity()*10)/4096);
	//return left()*(10/4096) * circumference;
}


double DriveTrain::Limit(double num, double max) {
	if (num > max)
		return max;

	if (num < -max)
		return -max;

	return num;
}