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

bool Circuit::gateOutputEquality(Event* e, Gate* g)
{
	double origVal = g->returnVal(g->getInput(1), g->getInput(2), g->getOutput(), g->getDelay(), g->getType());
	double newVal;
	Wire* w = new Wire();
	w->setValue(e->val);
	if (w->getValue() == g->getInput(1)->getValue()) {
		newVal = g->returnVal(g->getInput(1), w, g->getOutput(), g->getDelay(), g->getType());
	}
	else {
		newVal = g->returnVal(w, g->getInput(2), g->getOutput(), g->getDelay(), g->getType());
	}

	if (newVal == origVal) {
		return true;
	}
	else {
		return false;
	}
	
}


