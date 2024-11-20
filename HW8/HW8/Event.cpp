#pragma once
#include "Event.h"

Event::Event(string eventName, int eventTime, int eventCount, double eventVal)
{
	name = eventName;
	time = eventTime;
	val = eventVal;
	count = eventCount;
}

Event::Event()
{
	name = "";
	time = -4;
	val = -1;
	count = -7;
}

int Event::getCount() const
{
	return count;
}
