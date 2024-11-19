#include "Event.h"

Event::Event(string eventName, int eventTime, int eventCount, double eventVal)
{
	name = eventName;
	time = eventTime;
	val = eventVal;
	count = eventCount;
}

int Event::getCount() const
{
	return count;
}
