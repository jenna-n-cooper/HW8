#pragma once
#include "Event.h"
int numkey = 0;

Event::Event(string eventName, int eventTime, double eventVal)
{
	name = eventName;
	time = eventTime;
	val = eventVal;
	numkey++;
}

Event::Event()
{//set time at -4 so we know if it doesn't get properly changed
	name = "";
	time = -4;
	val = -1;
	numkey++;
}

int Event::getCount() const
{
	return numkey;
}
