#ifndef PistonRetract_H
#define PistonRetract_H

#include "../CommandBase.h"

class PistonRetract : public CommandBase {
public:
	PistonRetract();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PistonRetract_H
