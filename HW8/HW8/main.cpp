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
#include <stdexcept>

static int count = 0;

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

	try {

		inFile.open(cirFileName);

		if (inFile.fail()) {

			throw runtime_error("");
			

		}
	}
	catch (runtime_error& excpt) {

		cout << "Error opening circuit file." << endl;
		
		while (inFile.fail()) {

			cout << "Type in the circuit files name again. Enter 'end' to quit. ";
			getline(cin, cirName);

			if (cirName == "end") {

				cout << "exited simulation." << endl;
				return 0;

			}
			else {
				
				cirFileName = cirName + ".txt";
				vecFileName = cirName + "_v.txt";

				inFile.open(cirFileName);

			}

		}

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
	int in1, in2, out;
	double eventVal;

	

	
	while (!inFile.eof()) {
		getline(inFile, line);
		num_line++;
	}
	Circuit cir(num_line);
	inFile.seekg(fstream::beg);

	getline(inFile, line);
	while (!inFile.eof()) {
		//at every line in the Circuit file, create a wire
		inFile >> ioo;
		if (ioo == "INPUT" || ioo == "OUTPUT") {
			inFile >> wn >> wnum;
			newWire = new Wire();
			newWire->setName(wn);
			newWire->setIndex(wnum);
			newWire->setValue(0.5);

			cir.wires.at(wnum) = newWire;
			//add the input wires to inputs and the output wires to outputs
			if (ioo == "INPUT") {
				cir.inputs.at(wnum) = newWire;

			}
			else if (ioo == "OUTPUT") {
				cir.outputs.at(wnum) = newWire;
			}
		}
		else {
			//if it's a not gate, it will only have one input
			if (ioo == "NOT") {
				inFile >> sTime >> in1 >> out;
				//the second input is an empty wire 
				wireIn2 = new Wire();
			}
			else {
				//otherwise, it will have two inputs
				inFile >> sTime >> in1 >> in2 >> out;
				wireIn2 = cir.getOrCreateWire(in2);
			}
			
			sTime = sTime.substr(0, sTime.size() - 2);
			wireIn1 = cir.getOrCreateWire(in1);			
			wireOut = cir.getOrCreateWire(out);
			newGate = new Gate(wireIn1, wireIn2, wireOut, stoi(sTime), ioo);
			cir.gates.push_back(newGate);
			//make sure that all input wires are in the vector
			cir.addAllWiresToInputVector(newGate);
		}
		
		
	}

	cir.setAllDrivesForWires();

	inFile.close();

	inFile.open(vecFileName);

	if (inFile.fail()) {

		cout << "error opening vector file." << endl;
		return 1;

	}

	inFile.seekg(fstream::beg);

	getline(inFile, line);
	

	while (!inFile.eof()) {
		//at every line in the vector file, create an event and add it to the priority queue
		cir.pq = new priorityQueue;
		inFile >> ioo >> eventName >> eventTime >> eventVal;

		cir.pq->setKey(eventTime);
		cir.pq->setSKey(numkey);

		newEvent = new Event(eventName, eventTime, eventVal);
		cir.events.push_back(newEvent);

		cir.pq->setEvent(newEvent);
		
		cir.prio.push(*cir.pq);
		

	}

	//we have already created the events and priority queue. Now, we evaluate the gate
	while (cir.prio.size() != 0) {
		*cir.pq = cir.prio.top();
		if (cir.pq->getKey() > 60) {
			break;
		}
		cir.evaluateEvent(cir.pq);
		cir.prio.pop();
	}
	Wire printt;

	cout << endl << "Simulating " << cirFileName << ".";
	cir.printWires();
	printt.printTime();
	
	return 0;
}