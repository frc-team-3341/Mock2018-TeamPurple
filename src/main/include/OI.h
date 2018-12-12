/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include "Joystick.h"
//#include "Button.h"
//#include "JoystickButton.h"
//#include "Button.h"
#include "WPILib.h"

using namespace frc;

class OI {

 private:
  Joystick* leftStick;
  Joystick* rightStick;
  Button* servo;
 public:
  OI();
  Joystick* getLeftStick();
  Joystick* getRightStick();
 // Button* getServo();

};
