#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Wire.h"
#include "Gate.h"
#include "Circuit.h"

using namespace std;

int main() {

	string cirFileName;
	string vecFileName;
	string cirName;

	cout << "What circuit? (ex. circuit8) ";
	getline(cin, cirName);

	cirFileName = cirName + ".txt";
	vecFileName = cirName + "_V.txt";
	
	ifstream inFile;


	inFile.open(cirFileName);

	if (inFile.fail()) {

		cout << "error opening file." << endl;
		return 1;

	}


	Wire* newWire;

	string line;
	
	string ioo;
	string wn;
	int wnum;
	int num_line = 0;

	
	while (!inFile.eof()) {
		getline(inFile, line);
		num_line++;
	}
	Circuit cir(num_line);
	
	inFile.seekg(fstream::beg);

	getline(inFile, line);
	
	while (!inFile.eof()) {

		newWire = new Wire();
		
		inFile >> ioo >> wn >> wnum;

		if (ioo == "INPUT") {
			newWire->setName(wn);
			newWire->setIndex(wnum);
			newWire->setValue(0.5);
			
			cir.wires.at(wnum) = newWire;
			cir.inputs.at(wnum) = newWire;

		}
		else if (ioo == "OUTPUT") {
			newWire->setName(wn);
			newWire->setIndex(wnum);
			newWire->setValue(0.5);

			cir.wires.at(wnum) = newWire;
			cir.outputs.at(wnum) = newWire;
		}
		
	}

	inFile.close();

	return 0;
}