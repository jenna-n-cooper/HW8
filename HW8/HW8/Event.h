#pragma once
#include <string>

using namespace std;

class Event {
public:
	double val;
	int time, count;
	string name;

	Event(string eventName, int eventTime, int eventCount, double eventVal);

};
