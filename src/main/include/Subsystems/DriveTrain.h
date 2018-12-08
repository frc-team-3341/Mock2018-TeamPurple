/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include "ctre/Phoenix.h"
#include "RobotDrive.h"
#include "WPILib.h"
#include "math.h"

class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  TalonSRX* left;
  TalonSRX* right;
  RobotDrive* chassis;
  Ultrasonic* us;

 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void tankDrive(double leftPower, double rightPower);
  RobotDrive* getChassis();
  double getDistanceUltrasonic();
};
