#include "Wire.h"
#include <iostream>
#include <fstream>

Wire::Wire()
{
}

void Wire::setName(string cname)
{

	name = cname;

}

void Wire::setIndex(int cindex)
{

	index = cindex;

}

void Wire::setValue(double val)
{

	value = val;

}

void Wire::setHistory(vector<double>his)
{
	// wait until event class to fix

	// takes in vector with values index at specific times
	double curval = his.at(0);
	
	// goes through the whol vector
	for (int i = 1; i < his.size(); ++i) {

		// checks to see if the vector has something indexed
		if (his.at(i) != 1 || his.at(i) != 0 || his.at(i) != 0.5) {

			// if nothing, places the value of previous in spot
			his.at(i) = curval;

		}
		else {

			// if something is index there, changes that to the new value
			curval = his.at(i);

		}


	}


}

void Wire::setDrives(vector<Gate*> gate)
{

	for (int i = 0; i < gate.size(); ++i) {

		out.push_back(gate.at(i));

	}

}

double Wire::getValue() const
{
	return value;
}

string Wire::getName() const
{
	return name;
}

vector<Gate*> Wire::getDrives() const
{
	return out;
}

int Wire::getIndex() const
{
	return index;
}

void Wire::printHistory() const
{
	cout << name << " ";
	for (int i = 0; i < history.size(); i++) {
		if (history.at(i) == 0.5) {
			cout << "X";
		}
		else if (history.at(i) == 0) {
			cout << "0";
		}
		else {
			cout << "1";
		}
	}
	cout << endl;
}