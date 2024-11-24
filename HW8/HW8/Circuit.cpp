#pragma once
#include "Circuit.h"
#include <vector>
#include <queue>
#include "Wire.h"
#include "Gate.h"
#include "Event.h"
#include "priorityQueue.h"

static int count = 0;

using namespace std;

Circuit::Circuit(int numline)
{
	
	for (int i = 0; i < numline; i++) {
		inputs.push_back(nullptr);
		outputs.push_back(nullptr);
		wires.push_back(nullptr);
	}
	pq = nullptr;
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

Event* Circuit::outputChange(Event* e, Gate* g)
{
	Wire* ocWire = new Wire;
	string ocName;
	int ocTime, ocCount;
	double newVal; 

	// gets the wire* for the output wire

	// gets the name of the output wire
	ocName = g->getOutput()->getName();

	// gets the time delay. By time delay we mean the time that the event will take place
	// which is the time at which the current event took place + the time delay of the gate
	ocTime = e->time + g->getDelay();

	ocWire->setValue(e->val);
	// gets the new value of the output of the gate
	if (ocWire->getValue() == g->getInput(1)->getValue()) {
		newVal = g->returnVal(g->getInput(1), ocWire, g->getOutput(), g->getDelay(), g->getType());
	}
	else {
		newVal = g->returnVal(ocWire, g->getInput(2), g->getOutput(), g->getDelay(), g->getType());
	}

	//create event to change output wire using time
	Event* newEvent;

	newEvent = new Event(ocName, ocTime, newVal);


	//return Event* 
	return newEvent;
}

Wire* Circuit::getWireFromName(string wireName)
{
	
	//problem with differentiating between input and output
	//the are fewer items in the list than values when checking 
	//because it doesn't understand that there are
	
	for (int i = 1; i < inputs.size(); i++) {
		if (inputs.at(i) != nullptr && inputs.at(i)->getName() == wireName) {
			return inputs.at(i);
		}
		
	}

	for (int j = 1; j < outputs.size(); j++) {
		if (outputs.at(j) != nullptr && outputs.at(j)->getName() == wireName) {
			return outputs.at(j);
		}

	}
	return nullptr;
}

void Circuit::evaluateEvent(priorityQueue* cpq) {
	//getting our event and wires
	Event* newEvent = new Event; 
	priorityQueue* newQueue = new priorityQueue;
	Wire* w;
	int key;
	Event* e = cpq->getEvent();
	w = getWireFromName(e->name);
	//iterating through the drives
	for (int i = 0; i < w->getDrives().size(); i++) {
		//if the new output of the gate is different from the old, make an event
		if (!(gateOutputEquality(e, w->getDrives().at(i)))) {
			//create a new priorityQueue object
			newEvent = outputChange(e, w->getDrives().at(i));
			events.push_back(newEvent);
			key = newEvent->time;
			newQueue->setKey(key);
			newQueue->setEvent(newEvent);
			newQueue->setSKey(numkey);
			prio.push(*newQueue);
		}
	}
	//change wire value
	w->setValue(e->val);
	w->setVectorForHistory(w->getValue(), cpq);


}

void Circuit::printWires()
{//printing all input and output wires
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i) != nullptr) {
			inputs.at(i)->setHistory(inputs.at(i)->getHistory());
			inputs.at(i)->printHistory();
		}
	}

	for (int i = 0; i < outputs.size(); i++) {
		if (outputs.at(i) != nullptr) {
			outputs.at(i)->setHistory(outputs.at(i)->getHistory());
			outputs.at(i)->printHistory();
		}
	}
}

void Circuit::setAllDrivesForWires()
{
	for (int j = 0; j < inputs.size(); j++) {
		for (int i = 0; i < gates.size(); i++) {
			if (inputs.at(j) == gates.at(i)->getInput(1) || inputs.at(j) == gates.at(i)->getInput(2)) {
				inputs.at(j)->setDrives(gates.at(i));
			}
		}
	}
	
}



