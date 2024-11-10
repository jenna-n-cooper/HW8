#pragma once
#include <string>
#include <vector>
using namespace std;

class Gate;

class Wire {
private:
	char value;
	string name;
	vector<Gate*> out;
	int index;
	vector<char> history;

public:
	Wire();

	void setValue(char val);
	void setHistory(char his);
	void setDrives(vector<Gate*> gate);

	char getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;


};
