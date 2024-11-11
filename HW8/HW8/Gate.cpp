#include "Gate.h"
#include <iostream>
#include <fstream>

Gate::Gate(Wire* input1, Wire* input2, Wire* output, int d, string t)
{
	in1 = input1;//do I need to do a deep copy here?
	in2 = input2;
	out = output;
	delay = d;
	type = t;


}

int Gate::getDelay() const
{
	return delay;
}

Wire* Gate::getInput(int num) const
{
	if (num == 1) {
		return in1;
	}
	else if (num == 2) {
		return in2;
	}
	else {
		return nullptr;
	}
	
}

Wire* Gate::getOutput() const
{
	return out;
}

char Gate::returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const
{
	if (t == "AND") {

	}
	else if (t == "OR") {

	}

	return 0;
}
