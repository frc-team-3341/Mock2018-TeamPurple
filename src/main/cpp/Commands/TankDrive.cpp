/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/TankDrive.h"
#include "Robot.h"
#include <iostream>

TankDrive::TankDrive() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  std::cout << "help2" << std::endl;
  Requires(Robot::drive);
}

// Called just before this Command runs the first time
void TankDrive::Initialize() {
  std::cout << "help3" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void TankDrive::Execute() {
  Robot::drive->tankDrive(Robot::m_oi->getLeftStick()->GetY(), Robot::m_oi->getRightStick()->GetY());
//  std::cout << Robot::m_oi->getLeftStick()->GetY() << std::endl;
  // std::cout << Robot::m_oi->getLeftStick()->GetY() << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool TankDrive::IsFinished() { return false; }

// Called once after isFinished returns true
void TankDrive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TankDrive::Interrupted() {}
