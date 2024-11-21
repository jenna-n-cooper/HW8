#pragma once
#include <vector>
#include <queue>
#include "Event.h"
#include "priorityQueue.h"
typedef priority_queue <priorityQueue> myPQueue;

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
	priorityQueue* pq;
	myPQueue prio;

	Circuit(int numline);
	
	Wire* getOrCreateWire(int num);

	bool gateOutputEquality(Event* e, Gate* g);

	Event* outputChange(Event* e, Gate* g);

	Wire* getWireFromName(string wireName);

	void evaluateEvent(priorityQueue* cpq);

	void printWires();

};
