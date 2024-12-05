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

	// Prompts for Name of File
	cout << "What is the name of the circuit test file? (ex. circuit8) ";
	getline(cin, cirName);

	// creates the names of both files
	cirFileName = cirName + ".txt";
	vecFileName = cirName + "_v.txt";

	ifstream inFile;

	try {

		// opens circuit file
		inFile.open(cirFileName);


		// if the fail to open file, exception thrown
		if (inFile.fail()) {

			throw runtime_error("");


		}
	}
	// Allows user to retype the name until file opens or quit
	catch (runtime_error& excpt) {

		cout << "Error opening circuit file." << endl << endl;

		while (inFile.fail()) {

			cout << "Type in the circuit files name again. Enter 'end' to quit. ";
			getline(cin, cirName);

			if (cirName == "end") {

				cout << endl << "Exited simulation." << endl;
				return 0;

			}
			else {

				cirFileName = cirName + ".txt";
				vecFileName = cirName + "_v.txt";

				inFile.open(cirFileName);

			}

		}

	}

	Wire* newWire, * wireIn1, * wireIn2, * wireOut, * w;
	Gate* newGate;
	Event* newEvent, * e;

	string line;

	string ioo;
	string wn;
	string sTime, eventName;
	int wnum, eventTime;
	int num_line = 0;
	int in1, in2, out;
	double eventVal;

	// gets the number of lines the file has
	while (!inFile.eof()) {
		getline(inFile, line);
		num_line++;
	}
	
	// creates cir with that many slots
	Circuit cir(num_line);
	
	// sets back to the beginning of file
	inFile.seekg(fstream::beg);


	try {

		// takes in the first line to skip
		getline(inFile, line);
		while (!inFile.eof()) {
			inFile >> ioo;
			// sees if line is an input or output wire
			if (ioo == "INPUT" || ioo == "OUTPUT") {
				inFile >> wn >> wnum;
				if (isdigit(wnum)) {
					throw runtime_error("Circuit File Format Error WNUM");
				}
				// creates new wire with the inputed name and number for index, sets starting value of 0.5
				newWire = new Wire();
				newWire->setName(wn);
				newWire->setIndex(wnum);
				newWire->setValue(0.5);

				cir.wires.at(wnum) = newWire;

				// adds wire to either input or output to keep track of which is which
				if (ioo == "INPUT") {
					cir.inputs.at(wnum) = newWire;

				}
				else if (ioo == "OUTPUT") {
					cir.outputs.at(wnum) = newWire;
				}
			}
			// sees if line is a gate
			else if (ioo == "NOT" || ioo == "AND" || ioo == "OR" || ioo == "XOR"
				|| ioo == "NAND" || ioo == "NOR" || ioo == "XNOR") {
				// sets up NOT gate
				if (ioo == "NOT") {
					inFile >> sTime >> in1 >> out;
					wireIn2 = new Wire();
				}
				// sets up all other gates
				else {
					inFile >> sTime >> in1 >> in2 >> out;
					if (isdigit(in1) || isdigit(in2) || isdigit(out)) {
						throw runtime_error("Circuit File Format Error IN1 IN2 OUT");
					}
					wireIn2 = cir.getOrCreateWire(in2);
				}
				// creates the gate and puts it in the vector
				sTime = sTime.substr(0, sTime.size() - 2);
				wireIn1 = cir.getOrCreateWire(in1);
				wireOut = cir.getOrCreateWire(out);
				newGate = new Gate(wireIn1, wireIn2, wireOut, stoi(sTime), ioo);
				cir.gates.push_back(newGate);
				cir.addAllWiresToInputVector(newGate);
			}
			// if file isn't have one of options, throw execption for format error
			else {
				throw runtime_error("Circuit File Format Error NOT ANYTHING");
			}


		}
		// sets the drives for wires
		cir.setAllDrivesForWires();

		inFile.close();

		// opens vector file
		inFile.open(vecFileName);

		if (inFile.fail()) {

			cout << "error opening vector file." << endl;
			return 1;

		}

		// starts file at beginning
		inFile.seekg(fstream::beg);

		// takes in the line to skip
		getline(inFile, line);


		while (!inFile.eof()) {
			// starts the set up for priority queue
			cir.pq = new priorityQueue;
			inFile >> ioo >> eventName >> eventTime >> eventVal;

			// checks what is being read in is correct format
			if (ioo != "INPUT") {
				throw runtime_error("Vector File Format Error");
			}

			if (isdigit(eventTime)) {
				throw runtime_error("Vector File Format Error");
			}
			// sets the first key as the time
			cir.pq->setKey(eventTime);
			// sets the second key as when inputed in the queue
			cir.pq->setSKey(numkey);
			// creates the event to put in the queue
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
		
		Wire print;


		cout << endl << "Simulating " << cirFileName << ".";
		
		// prints the history of the wires
		cir.printWires();
		// prints the time 
		int maxHistSize = 0;
		for (int i = 0; i < cir.wires.size(); i++) {
			if (cir.wires.at(i) != nullptr && cir.wires.at(i)->getName() != "") {
				if (cir.wires.at(i)->getHistorySize() > maxHistSize) {
					maxHistSize = cir.wires.at(i)->getHistorySize();
				}
			}
		}
		print.setHistorySize(maxHistSize);
		print.printTime();

		return 0;
	}
	catch (runtime_error& excpt) {

		cout << excpt.what() << endl;

	}


}