#include "Commands/Middle.h"
#include "Commands/DriveForward.h"
#include "Commands/Turn.h"
#include "Commands/AutoBucketMove.h"
#include "Commands/BucketMove.h"
#include <iostream>


Middle::Middle() {
	//AddSequential(new DriveForward(8*12));
	AddParallel(new BucketMove(1));
	AddSequential(new DriveForward(79));
	std::cout << "step 1" << std::endl;
	AddSequential(new AutoBucketMove(5000));
	std::cout << "step 2" << std::endl;

}
