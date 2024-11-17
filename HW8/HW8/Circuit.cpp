#include "Circuit.h"
#include "Wire.h"
#include "Gate.h"

Circuit::Circuit(int numline)
{
	
	for (int i = 0; i < numline; i++) {
		inputs.push_back(nullptr);
		outputs.push_back(nullptr);
		wires.push_back(nullptr);
		gates.push_back(nullptr);
	}
}

Wire* Circuit::getOrCreateWire(int num)
{
	if (wires.at(num) != nullptr) {
		return wires.at(num);
	}
	else {
		Wire* w = new Wire;
		w->setIndex(num);
		wires.at(num) = w;
		inputs.at(num) = w;
		return wires.at(num);
	}
}

bool Circuit::gateOutputEquality(Event* event1)
{
	Wire* origWire = getWireFromName(event1->name);
	vector<Gate*> g = getGatesFromName(event1->name);
	for (int i = 0; i < g.size(); i++) {
		if (g.at(i)->getInput(1) == origWire) {

		}
	}
	return false;
}

Wire* Circuit::getWireFromName(string wireName)
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i)->getName() == wireName) {
			return inputs.at(i);
		}
	}
	return nullptr;
}


vector<Gate*> Circuit::getGatesFromName(string wireName)
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i)->getName() == wireName) {
			return inputs.at(i)->getDrives();
		}
	}
	return vector<Gate*>();
}
