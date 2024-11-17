#pragma once
#include <string>

using namespace std;

class Event {
public:
	double val;
	int time;
	string name;

	Event(string eventName, int eventTime, double eventVal);

};
