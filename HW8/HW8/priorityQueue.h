#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <queue>
#include "Event.h"

using namespace std;

class priorityQueue {

public:
	priorityQueue() : key(0), secondaryKey(0), pqEvents() {  }

	priorityQueue(int ky, int sk, Event* events) : key(ky), secondaryKey(sk), pqEvents(events) { }

	int    getKey()      const { return key; }
	void   setKey(int k) { key = k; }

	int    getSKey()      const { return secondaryKey; }
	void   setSKey(int sk) { secondaryKey = sk; }

	Event* getEvent() const { return pqEvents; }
	void   setEvent(Event* events) { pqEvents = events; }

	friend bool operator <(const priorityQueue& p1, const priorityQueue& p2);

private:
	int   key;
	int	  secondaryKey;

	Event* pqEvents;



};