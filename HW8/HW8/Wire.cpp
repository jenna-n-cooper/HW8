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

void Wire::setHistory(double his)
{//when an event is called, call the setHistory function

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

bool Wire::getorCreateWire()
{

	if (!w.at(index))
	return false;
}
