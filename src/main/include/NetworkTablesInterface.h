/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#ifndef NETWORKTABLESINTERFACE_H_
#define NETWORKTABLESINTERFACE_H_


#include "NetworkTables/NetworkTableInstance.h"

class NetworkTablesInterface {
public:

	static double getDistance();
	static double getAngle();
	static double getAltitude();
};

#endif /* NETWORKTABLESINTERFACE_H_ */
