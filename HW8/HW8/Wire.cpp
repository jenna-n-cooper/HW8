#include "Wire.h"

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
	return 0;
}

string Wire::getName() const
{
	return string();
}

vector<Gate*> Wire::getDrives() const
{
	return vector<Gate*>();
}

int Wire::getIndex() const
{
	return 0;
}

void Wire::printHistory() const
{
}
