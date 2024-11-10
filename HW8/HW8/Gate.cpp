#include "Gate.h"

Gate::Gate(Wire* input1, Wire* input2, Wire* output, int d, string t)
{
}

int Gate::getDelay() const
{
	return 0;
}

Wire* Gate::getInput(int num) const
{
	return nullptr;
}

Wire* Gate::getOutput() const
{
	return nullptr;
}

char Gate::returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const
{
	return 0;
}
