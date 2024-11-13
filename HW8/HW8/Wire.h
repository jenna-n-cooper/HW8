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
	vector<double> history;

public:
	Wire();

	void setName(string cname);
	void setIndex(int cindex);
	void setValue(double val);


	void setHistory(vector<double>history);
	void setDrives(vector<Gate*> gate);

	double getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;



};
