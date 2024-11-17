#pragma once
#include <string>
#include <vector>
using namespace std;

class Gate;

class Wire {
private:
	double value;
	string name;
	vector<Gate*> out;
	int index;
	vector<double> history;

public:
	Wire();
	//we need to make a destructor for the wires and probably also the gates
	void setName(string cname);
	void setIndex(int cindex);
	void setValue(double val);


	void setHistory(double his);
	void setDrives(vector<Gate*> gate);

	double getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;



};
