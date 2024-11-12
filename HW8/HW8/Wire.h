#pragma once
#include <string>
#include <vector>
using namespace std;

class Gate;

class Wire {
private:
	int value;
	string name;
	vector<Gate*> out;
	int index;
	vector<char> history;

public:
	Wire();

	void setValue(double val);//when a wire has value X, set it to value 0.5
	void setHistory(char his);
	void setDrives(vector<Gate*> gate);

	double getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;


};
