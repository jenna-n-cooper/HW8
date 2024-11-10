#include "Wire.h"
#include <iostream>
#include <fstream>

Wire::Wire()
{
}

void Wire::setValue(char val)
{
}

void Wire::setHistory(char his)
{
}

void Wire::setDrives(vector<Gate*> gate)
{

}

char Wire::getValue() const
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
