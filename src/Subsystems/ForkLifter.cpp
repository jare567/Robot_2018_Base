#include "ForkLifter.h"
#include "../RobotMap.h"

#define UP 1.0 // FIXME: test and use actual motor direction
#define DN -1.0 //FIXME: " "

ForkLifter::ForkLifter() : frc::Subsystem("ForkLifter")
{
	lm = new WPI_TalonSRX(6); // Lifter motor

}

void ForkLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ForkLifter::Raise()
{
	lm->Set(UP);

}

void ForkLifter::Lower()
{

	lm->Set(DN);
}

void ForkLifter::Stop()
{

	lm->Set(0.0);
}
