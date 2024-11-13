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
}

bool Wire::getorCreateWire()
{
	if (!w.at(index))
	return false;
}
