#ifndef GrabbArms_H
#define GrabbArms_H
#include <ctre/Phoenix.h>
#include "Commands/Subsystem.h"

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
};

#endif  // GrabbArms_H
