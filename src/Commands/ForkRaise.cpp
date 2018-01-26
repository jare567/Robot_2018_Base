#include "ForkRaise.h"

ForkRaise::ForkRaise()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(forklifter);
}

// Called just before this Command runs the first time
void ForkRaise::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ForkRaise::Execute()
{
	double ForkMove;

	if((ForkMove = GetRightTrig()) > TRIGGER_DEADBAND)
	{
		forklifter->Raise(ForkMove);
	}
	else if((ForkMove = GetLeftTrig()) > TRIGGER_DEADBAND)
	{
		forklifter->Lower(ForkMove);
	}
	else
		forklifter->Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool ForkRaise::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ForkRaise::End()
{
	forklifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkRaise::Interrupted()
{
	forklifter->Stop();
}

double ForkRaise::GetLeftTrig()
{
	return oi->xboxController->GetRawAxis(2); //Left trigger
}

double ForkRaise::GetRightTrig()
{
	return oi->xboxController->GetRawAxis(3); //Right trigger
}
