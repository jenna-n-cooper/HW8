#pragma once
#include <vector>
#include <string>
#include "Wire.h"
#include <iostream>
#include <algorithm>//for the min() and max() functions
#include <fstream>
using namespace std;

class Wire;

class Gate {
private:
	Wire* in1, * in2;
	Wire* out;
	int delay;
	string type;

public:
	Gate(Wire* input1, Wire* input2, Wire* output, int d, string t);
	int getDelay() const;
	Wire* getInput(int num) const;
	Wire* getOutput() const;
	string getType() const;
	double negateVal(double val) const;

	double returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const;

};