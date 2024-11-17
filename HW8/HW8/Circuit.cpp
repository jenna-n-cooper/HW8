#include "Circuit.h"
#include "Wire.h"

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
	
	return false;
}

int Circuit::getWireIndexFromName(Wire* wire1, string wireName)
{
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i)->getName() == wireName) {
			return inputs.at(i)->getValue();
		}
	}
	return -5;
}
