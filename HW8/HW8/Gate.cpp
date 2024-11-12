#include "Gate.h"
#include "Wire.h"
#include <iostream>
#include <algorithm>//for the min() and max() functions
#include <fstream>

using namespace std;

Gate::Gate(Wire* input1, Wire* input2, Wire* output, int d, string t)
{
	in1 = input1;
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

double Gate::returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const
{
	if (t == "AND") {
		return min(input1->getValue(), input2->getValue());
	}
	else if (t == "OR") {
		return max(input1->getValue(), input2->getValue());
	}

	return 0;
}
