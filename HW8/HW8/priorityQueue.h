#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <queue>

using namespace std;

class priorityQueue {

	public:
		priorityQueue() : key(0), secondaryKey(0), s("") {  }
	
		//change  string to be for event class vector of event 
		priorityQueue(int ky, int sk, string str) : key(ky), secondaryKey(sk), s(str) {  }
		int    getKey()      const { return key; }
		void   setKey(int k) { key = k; }
		int    getSKey()      const { return secondaryKey; }
		string getString()    const { return s; }
		friend bool operator<(const priorityQueue& p1, const priorityQueue& p2);
	private:
		int   key;
		int	  secondaryKey;
	
		// make for event class
		string s;
};

bool operator<(const priorityQueue& p1, const priorityQueue& p2) {

	// by default the queue is a MAX queue, so we reverse the comparison
	// from '<' to '>' (see the return statements) to make it a MIN queue
	if (p1.key == p2.key) {
		return p1.secondaryKey > p2.secondaryKey;
	}

	return p1.key > p2.key;
}