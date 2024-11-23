#pragma once
#include <string>
#include <queue>

using namespace std;

extern int numkey;

class Event {
public:
	double val;
	int time;
	string name;

	Event(string eventName, int eventTime, double eventVal);
	Event();
	int getCount() const;

};
