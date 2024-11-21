#pragma once
#include <string>
#include <queue>

using namespace std;

class Event {
public:
	double val;
	int time, count;
	string name;

	Event(string eventName, int eventTime, int eventCount, double eventVal);
	Event();
	int getCount() const;

};
