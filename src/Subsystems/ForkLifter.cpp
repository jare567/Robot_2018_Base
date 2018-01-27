#include "ForkLifter.h"
#include "../RobotMap.h"


ForkLifter::ForkLifter() : frc::Subsystem("ForkLifter")
{
	lm = new WPI_TalonSRX(POWERCUBE_LIFTER_ID); // Lifter motor

}

void ForkLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void ForkLifter::Raise(double speed)
{
	lm->Set(speed);

}

void ForkLifter::Lower(double speed)
{

	lm->Set(-speed);
}

void ForkLifter::Stop()
{

	lm->Set(0.0);
}
