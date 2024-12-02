#pragma once
#include "Wire.h"
#include <iostream>
#include <fstream>
using namespace std;

Wire::Wire()
{
	value = 0.5;
	name = "";
	index = -1;
	out = {};
	history.resize(61);
	for (int i = 0; i < history.size(); i++) {

		history.at(i) = 0.5;

	}

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

void Wire::setVectorForHistory(double histVec, priorityQueue* pq)
{
	int histTime;
	histTime = pq->getKey();

	history.at(histTime) = histVec;

}

void Wire::setHistory(vector <double> his)
{
	// wait until event class to fix
	//history.push_back(his);

	// takes in vector with values index at specific times
	double curval = history.at(0);

	// goes through the whole vector
	for (int i = 1; i < history.size(); ++i) {
		// checks to see if the vector has something indexed

		double somet = history.at(i);

		if (somet == 0.5) {
			// if nothing, places the value of previous in spot
			history.at(i) = curval;
		}
		else {
			// if something is index there, changes that to the new value
			curval = history.at(i);
		}
	}

}

void Wire::setDrives(Gate* gate)
{
	out.push_back(gate);
}

vector<double> Wire::getHistory() const
{
	
	return history;

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

void Wire::printTime() const
{
	cout << endl << "T:";
	for (int i = 0; i < history.size(); i = i + 5) {

		if (i < 6) {
			cout << i << "    ";
		}
		if (i > 6) {
			cout << i << "   ";
		}
		
	}

	cout << endl << endl;

}
