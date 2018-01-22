#ifndef ForkLower_H
#define ForkLower_H

#include "../CommandBase.h"

class ForkLower : public CommandBase {
public:
	ForkLower();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ForkLower_H
