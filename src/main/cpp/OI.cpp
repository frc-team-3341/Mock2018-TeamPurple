/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "ctre/Phoenix.h"
#include <WPILib.h>
#include "Commands/BucketMove.h"

OI::OI() : leftStick(new Joystick(1)), rightStick(new Joystick(1)), servo(new JoystickButton(leftStick, 11)) {
  // Process operator interface input here.
  servo->WhenPressed(new BucketMove(1));
  servo->WhenReleased(new BucketMove(0));
}

Joystick* OI::getLeftStick()
{
  return leftStick;
}

Joystick* OI::getRightStick()
{
  return rightStick;
}

