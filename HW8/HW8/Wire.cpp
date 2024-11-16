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
	history = {};

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

void Wire::setHistory(double his)
{
	// wait until event class to fix
	history.push_back(his);

}

void Wire::setDrives(vector<Gate*> gate)
{

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