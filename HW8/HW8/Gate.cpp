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

double Gate::negateVal(double val) const
{
	if (val == 0) {
		return 1.0;
	}
	else if (val == 1) {
		return 0.0;
	}
	else if (val == 0.5) {
		return 0.5;
	}
	else {
		cout << "invalid value";
		return 0.0;
	}
}

double Gate::returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const
{//one of “NOT”, “AND”, “OR”, “XOR”, “NAND”, “NOR”, and “XNOR”
	if (t == "AND") {
		return min(input1->getValue(), input2->getValue());
	}
	else if (t == "NAND") {
		return negateVal(min(input1->getValue(), input2->getValue()));
	}
	else if (t == "OR") {
		return max(input1->getValue(), input2->getValue());
	}
	else if (t == "NOR"){
		return negateVal(max(input1->getValue(), input2->getValue()));
	}
	else if (t == "XOR") {//not sure if this gate logic is correct
		if (input1->getValue() == input2->getValue()) {
			return 0.0;
		}
		else {
			if (input1->getValue() == 1 || input2->getValue() == 1) {
				return 1.0;
			}
			else {
				return 0.5;
			}
		}
	}
	else if (t == "XNOR") {
		double num;
		if (input1->getValue() == input2->getValue()) {
			num = 0.0;
		}
		else {
			if (input1->getValue() == 1 || input2->getValue() == 1) {
				num = 1.0;
			}
			else {
				num = 0.5;
			}
		}
		return negateVal(num);

	}
	else if (t == "NOT") {
		if (input1->getValue() == 1) {
			return 0.0;
		}
		else if (input1->getValue() == 0) {
			return 1.0;
		}
		else {
			return 0.0;
		}
		
	}

	return 0.0;
}
