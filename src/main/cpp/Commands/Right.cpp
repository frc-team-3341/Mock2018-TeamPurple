#include "Commands/Right.h"
#include "Commands/DriveForward.h"
#include "Commands/Turn.h"
#include "Commands/AutoBucketMove.h"


Right::Right() {
	AddSequential(new DriveForward(12));
	AddSequential(new Turn(25));
	AddSequential(new DriveForward(58));
	AddSequential(new Turn(-25));
	AddSequential(new DriveForward(10));
	AddSequential(new AutoBucketMove(5000));
}
