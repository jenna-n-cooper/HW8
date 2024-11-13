#pragma once
#include <vector>

using namespace std;
class Wire;
class Gate;

class Circuit {
public:
	//we should probably make these private variables at some point 
	vector <Wire*> inputs;
	vector <Wire*> outputs;
	vector <Wire*> wires;
	vector <Gate*> gates;

	Circuit(int numline);



};
