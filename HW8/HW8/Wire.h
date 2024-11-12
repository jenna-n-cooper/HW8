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
	/*vector <Wire*> w;
	vector <Wire*> inputs;
	vector <Wire*> outputs;*/

public:
	Wire();

	void setName(string cname);
	void setIndex(int cindex);
	void setValue(double val);


	void setHistory(char his);
	void setDrives(vector<Gate*> gate);

	double getValue() const;
	string getName() const;
	vector<Gate*> getDrives() const;
	int getIndex() const;
	
	void printHistory() const;


};
