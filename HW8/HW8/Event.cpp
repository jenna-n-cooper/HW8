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
{
	name = "";
	time = -4;
	val = -1;
	numkey = -7;
}

int Event::getCount() const
{
	return numkey;
}
