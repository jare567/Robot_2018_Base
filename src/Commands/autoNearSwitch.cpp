#include "autoNearSwitch.h"
#include "ForkMoveToDistance.h"
#include "autoTimedMove.h"

autoNearSwitch::autoNearSwitch() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.


	AddSequential(new autoTimedMove(5));
	//AddSequential(new ForkMoveToDistance(3));
	// AddSequential(autoTurn(90));
	// AddSequental(autoTimedMove(1));
	// AddSequential(autoDropPowerCube);

}
