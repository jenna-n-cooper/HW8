#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include "Wire.h"
#include "Gate.h"
#include "Circuit.h"
#include "Event.h"
#include "crtdbg.h"
#include "priorityQueue.h"

using namespace std;


int main() {

	string cirFileName;
	string vecFileName;
	string cirName;

	cout << "What circuit? (ex. circuit8) ";
	getline(cin, cirName);

	cirFileName = cirName + ".txt";
	vecFileName = cirName + "_v.txt";
	
	ifstream inFile;


	inFile.open(cirFileName);

	if (inFile.fail()) {

		cout << "error opening circuit file." << endl;
		return 1;

	}



	Wire* newWire, *wireIn1, *wireIn2, *wireOut, *w;
	Gate* newGate;
	Event* newEvent, *e;

	string line;
	
	string ioo;
	string wn;
	string sTime, eventName;
	int wnum, eventTime;
	int num_line = 0;
	int in1, in2, out, eventCount = 0;
	double eventVal;

	

	
	while (!inFile.eof()) {
		getline(inFile, line);
		num_line++;
	}
	Circuit cir(num_line);
	inFile.seekg(fstream::beg);

	getline(inFile, line);
	while (!inFile.eof()) {
		inFile >> ioo;
		if (ioo == "INPUT" || ioo == "OUTPUT") {
			inFile >> wn >> wnum;
			newWire = new Wire();
			newWire->setName(wn);
			newWire->setIndex(wnum);
			newWire->setValue(0.5);

			cir.wires.at(wnum) = newWire;

			if (ioo == "INPUT") {
				cir.inputs.at(wnum) = newWire;

			}
			else if (ioo == "OUTPUT") {
				cir.outputs.at(wnum) = newWire;
			}
		}
		else {
			if (ioo == "NOT") {
				inFile >> sTime >> in1 >> out;
				wireIn2 = new Wire();
			}
			else {
				inFile >> sTime >> in1 >> in2 >> out;
				wireIn2 = cir.getOrCreateWire(in2);
			}
			
			sTime = sTime.substr(0, sTime.size() - 2);
			wireIn1 = cir.getOrCreateWire(in1);			
			wireOut = cir.getOrCreateWire(out);
			newGate = new Gate(wireIn1, wireIn2, wireOut, stoi(sTime), ioo);
		}
		
		
	}

	inFile.close();

	inFile.open(vecFileName);

	if (inFile.fail()) {

		cout << "error opening vector file." << endl;
		return 1;

	}

	inFile.seekg(fstream::beg);

	getline(inFile, line);

	while (!inFile.eof()) {
		inFile >> ioo >> eventName >> eventTime >> eventVal;
		eventCount++;

		cir.pq.setKey(eventTime);
		cir.pq.setSKey(eventCount);

		newEvent = new Event(eventName, eventTime, eventCount, eventVal);
		cir.events.push_back(newEvent);

		cir.pq.setEvent(newEvent);
		
		cir.prio.push(cir.pq);


	}

	//we have already created the events and priority queue. Now, we evaluate the gate
	while (cir.prio.size() != 0) {
		cir.pq = cir.prio.top();
		cir.evaluateEvent(cir.pq);
		cir.prio.pop();
	}
	



	return 0;
}