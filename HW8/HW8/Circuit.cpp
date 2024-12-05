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
	//set all values to nullptr
	for (int i = 0; i < numline; i++) {
		inputs.push_back(nullptr);
		outputs.push_back(nullptr);
		wires.push_back(nullptr);
	}
	pq = nullptr;
}

Wire* Circuit::getOrCreateWire(int num)
{//if there is a wire at this val return it. Otherwise, create a new wire
	if (wires.at(num) != nullptr) {
		return wires.at(num);
	}
	else {
		Wire* w = new Wire;//dynamically allocate new memory for the wire pointer
		w->setIndex(num);
		wires.at(num) = w;
		inputs.at(num) = w;
		return wires.at(num);
	}
}

bool Circuit::gateOutputEquality(Event* e, Gate* g)
{
	//find the original result of the gate evaluation
	double origVal = g->returnVal(g->getInput(1), g->getInput(2), g->getOutput(), g->getDelay(), g->getType());
	double newVal;
	Wire* w = new Wire();
	w->setValue(e->val);
	//find the new value
	if (getWireFromName(e->name) == g->getInput(2)) {
		newVal = g->returnVal(g->getInput(1), w, g->getOutput(), g->getDelay(), g->getType());
	}
	else {
		newVal = g->returnVal(w, g->getInput(2), g->getOutput(), g->getDelay(), g->getType());
	}
	//if they are the same, GateOutputEquality is true
	if (newVal == origVal) {
		return true;
	}
	else {
		return false;
	}
	
}

bool Circuit::areInputWiresInInputVector(Wire* w)
{//make sure all input wires are in vector. (some input wires are classified as output in the circuit text file
	for (int i = 0; i < inputs.size(); i++) {
		if (inputs.at(i) == w) {
			return true;
		}
	}
	return false;
}

void Circuit::addAllWiresToInputVector(Gate* g)
{//if the wire is not added to the input vector, add it. 
	if (!(areInputWiresInInputVector(g->getInput(1)))) {
		inputs.at(g->getInput(1)->getIndex()) = g->getInput(1);
	}
	if (!(areInputWiresInInputVector(g->getInput(2)))) {
		inputs.at(g->getInput(2)->getIndex()) = g->getInput(2);
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
	if (getWireFromName(e->name) == g->getInput(2)) {
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
	//getting wire from name. first we check inputs and then outputs
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
			//add the object to the priority queue
			prio.push(*newQueue);
		}
	}
	//change wire value and set history
	w->setValue(e->val);
	w->setVectorForHistory(w->getValue(), cpq);


}

void Circuit::printWires()
{//printing all input and output wires
	
	cout << endl << endl << endl;

	cout << "Wire traces: " << endl;
	
	for (int i = 0; i < wires.size(); i++) {
		if (wires.at(i) != nullptr && wires.at(i)->getName() != "") {
			wires.at(i)->setHistory(wires.at(i)->getHistory());
			wires.at(i)->printHistory();
		}
	}
}

void Circuit::setAllDrivesForWires()
{//making sure all the wires point to the gates that they drive
	//iterating through all the wires and gates
	for (int j = 0; j < inputs.size(); j++) {
		for (int i = 0; i < gates.size(); i++) {
			if (inputs.at(j) == gates.at(i)->getInput(1) || inputs.at(j) == gates.at(i)->getInput(2)) {
				inputs.at(j)->setDrives(gates.at(i));
			}
		}
	}
	
}



