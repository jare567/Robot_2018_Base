#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static pointer/instance of all of your subsystems to NULL
OI* CommandBase::oi = NULL;
DriveTrain* CommandBase::drivetrain = NULL;
Piston*	CommandBase::piston = NULL;
Utility* CommandBase::utility = NULL;
//Camera* CommandBase::camera = NULL;
ForkLifter* CommandBase::forklifter = NULL;

CommandBase::CommandBase(char const *name): Command(name) {}

CommandBase::CommandBase(): Command() {}

void CommandBase::init()
{
	drivetrain = new DriveTrain();
	oi = new OI();
//	datalogger = new DataLogger();
	piston = new Piston();
//	camera = new Camera();
	utility = new Utility();
	forklifter = new ForkLifter();
}
