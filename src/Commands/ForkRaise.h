#ifndef ForkRaise_H
#define ForkRaise_H

#include "../CommandBase.h"

class ForkRaise : public CommandBase {
public:
	ForkRaise();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkRaise_H
