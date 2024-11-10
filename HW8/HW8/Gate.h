#pragma once
#include <vector>
#include <string>
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

	char returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const;

};