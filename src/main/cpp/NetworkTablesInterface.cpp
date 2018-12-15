/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "NetworkTablesInterface.h"


double NetworkTablesInterface::getDistance()
{
	//return nt::NetworkTableInstance::GetDefault().GetEntry("cv").GetString("100"); // -1 default

	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("distance").GetDouble(-1);	//if -1 then cv value does not exist

}

double NetworkTablesInterface::getAltitude()
{
	return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("altitude").GetDouble(-1);
}

double NetworkTablesInterface::getAngle() {
return nt::NetworkTableInstance::GetDefault().GetTable("cv")->GetEntry("angle").GetDouble(-1);
	//returns true if the gear has been detected
}
