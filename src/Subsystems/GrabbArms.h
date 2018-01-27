#ifndef GrabbArms_H
#define GrabbArms_H
#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"

class GrabbArms : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX *larm; // left arm
	WPI_TalonSRX *rarm; // right arm

public:
	GrabbArms();
	void InitDefaultCommand();
	void RightIn();
	void RightStop();
	void LeftIn();
	void LeftStop();
	void Eject();
	void AllStop();


};

#endif  // GrabbArms_H
