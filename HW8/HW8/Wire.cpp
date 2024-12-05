#pragma once
#include "Wire.h"
#include <iostream>
#include <fstream>
using namespace std;

Wire::Wire()
{//set value at -0.5 so that we know when it has been changed
	value = -0.5;
	name = "";
	index = 0;
	out = {};
	history.resize(61);
	for (int i = 0; i < history.size(); i++) {

		history.at(i) = -0.5;

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
{//set the changed value at the time that it changes
	int histTime;
	histTime = pq->getKey();
	if (histTime < history.size()) {
		history.at(histTime) = histVec;
	}
}

void Wire::setHistory(vector <double> his)
{

	// changes curval and history.at(0) if the value has not been changed at time 0
	double curval = history.at(0);
	if (curval == -0.5) {
		curval = 0.5;
		history.at(0) = 0.5;
	}

	// goes through the whole vector
	for (int i = 1; i < history.size(); ++i) {
		// checks to see if the vector has something indexed

		double somet = history.at(i);

		if (somet == -0.5) {
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
	cout << endl << " " << name << " " << "|" << " ";
	for (int i = 0; i < history.size(); i++) {//prints an X for no val, and then _ for 0 and - for 1
		if (history.at(i) == 0.5) {
			cout << "X";
		}
		else if (history.at(i) == 0) {
			cout << "_";
		}
		else {
			cout << "-";
		}
	}
	cout << endl << "   |" ;
	
}

void Wire::printTime() const
{
	//prints the bar above the time indices
	cout << "_______________________________________________________________" << endl << " T:  " << "";
	for (int i = 0; i < history.size(); i = i + 5) {
		//prints the time indices
		if (i < 6) {
			cout << i << "    ";
		}
		if (i > 6) {
			cout << i << "   ";
		}
		
	}

	cout << endl << endl;

}
