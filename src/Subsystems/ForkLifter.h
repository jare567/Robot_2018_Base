#ifndef ForkLifter_H
#define ForkLifter_H

#include <Commands/Subsystem.h>
#include <ctre/Phoenix.h>
#include "WPILib.h"

class ForkLifter : public Subsystem
{
private:

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	WPI_TalonSRX *lm;

public:
	ForkLifter();
	void InitDefaultCommand();
	void Raise();
	void Lower();
	void Stop();
};

#endif  // ForkLifter_H
