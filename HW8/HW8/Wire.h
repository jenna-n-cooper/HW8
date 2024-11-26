#pragma once
#include <string>
#include <vector>
#include "priorityQueue.h"
using namespace std;

class Gate;

class Wire {
private:
	double value;
	string name;
	vector<Gate*> out;
	int index;
	vector <double> history;

public:
	Wire();
	//we need to make a destructor for the wires and probably also the gates
	void setName(string cname);
	void setIndex(int cindex);
	void setValue(double val);

	void setVectorForHistory(double hisvec, priorityQueue* pq);

	void setHistory(vector<double> his);

	void setDrives(Gate* gate);

	vector<double> getHistory() const;

	double getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;
	void printTime() const;



};
