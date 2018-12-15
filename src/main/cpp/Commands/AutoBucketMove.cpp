/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Commands/AutoBucketMove.h"
#include <iostream>

AutoBucketMove::AutoBucketMove(double timeout)
    : TimedCommand(timeout) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::servo);
  std::cout << "step 1" << std::endl;
}

// Called just before this Command runs the first time
void AutoBucketMove::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoBucketMove::Execute() 
{
  Robot::servo->move(0.2);
    std::cout << "step 5" << std::endl;

}

// Called once after command times out
void AutoBucketMove::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoBucketMove::Interrupted() {}
