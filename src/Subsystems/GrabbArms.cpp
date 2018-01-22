#include "GrabbArms.h"
#include "../RobotMap.h"

GrabbArms::GrabbArms() : Subsystem("GrabbArms")
{
	larm = new WPI_TalonSRX(ARM_LEFT_MOTOR_ID); // left arm
	// rarm = new WPI_TalonSRX(ARM_RIGHT_MOTOR_ID); // right arm FIXME needs two motors
}

void GrabbArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
