#pragma once
#include <vector>

using namespace std;
class Wire;
class Gate;

class Circuit {
public:

	vector <Wire*> inputs;
	vector <Wire*> outputs;
	vector <Wire*> w;
	vector <Gate*> gates;



};
