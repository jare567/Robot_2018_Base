#include "ForkRaise.h"

ForkRaise::ForkRaise() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ForkRaise::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ForkRaise::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool ForkRaise::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ForkRaise::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ForkRaise::Interrupted() {

}
