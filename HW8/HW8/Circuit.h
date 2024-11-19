#pragma once
#include <vector>
#include "Event.h"

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
	vector <Event*> events;

	Circuit(int numline);
	
	Wire* getOrCreateWire(int num);

	bool gateOutputEquality(Event* e, Gate* g);


};
