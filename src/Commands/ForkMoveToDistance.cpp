#include "ForkMoveToDistance.h"

ForkMoveToDistance::ForkMoveToDistance(double dist)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(forklifter);
	//int current = forklifter->ReadEncoder();
	target = (int)(dist * TICS_PER_INCH);

}

// Called just before this Command runs the first time
void ForkMoveToDistance::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ForkMoveToDistance::Execute()
{
	if (target > forklifter->ReadEncoder())
	{
		forklifter->Raise(FORK_SPEED); //TODO: figure out needed FORK_SPEED
	}
	else
	{
		forklifter->Lower(FORK_SPEED); //TODO: figure out needed FORK_SPEED
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ForkMoveToDistance::IsFinished()
{
	return ((abs(target - forklifter->ReadEncoder())) < FORK_DISTANCE_DEADBAND);
}

// Called once after isFinished returns true
void ForkMoveToDistance::End()
{
	forklifter->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkMoveToDistance::Interrupted()
{
	forklifter->Stop();
}
