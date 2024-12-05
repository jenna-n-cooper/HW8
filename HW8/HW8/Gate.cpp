#include "Gate.h"


using namespace std;

Gate::Gate(Wire* input1, Wire* input2, Wire* output, int d, string t)
{
	in1 = input1;
	in2 = input2;
	out = output;
	delay = d;
	type = t;


}

int Gate::getDelay() const
{
	return delay;
}

Wire* Gate::getInput(int num) const
{//returns the desired input
	if (num == 1) {
		return in1;
	}
	else if (num == 2) {
		return in2;
	}
	else {
		return nullptr;
	}
	
}

Wire* Gate::getOutput() const
{
	return out;
}

string Gate::getType() const
{
	return type;
}

double Gate::negateVal(double val) const
{
	return 1 - val;//since the "base val" is 0.5, we can get the negation of each value by doing 1- val. 
	                //ex: 1 - 0 = 1, 1 - 1 = 0, 1 - 0.5 = 0.5 (this is a concept from fuzzy logic)
}

double Gate::returnVal(Wire* input1, Wire* input2, Wire* output, int d, string t) const
{//one of “NOT”, “AND”, “OR”, “XOR”, “NAND”, “NOR”, and “XNOR”
	if (t == "AND") {

		if (input1->getValue() == 0.5 || input2->getValue() == 0.5) {
			return 0.5;
		}
		else {
			return min(input1->getValue(), input2->getValue());//the and function returns the min of the values
		}
	}
	else if (t == "NAND") {
		return negateVal(min(input1->getValue(), input2->getValue())); //the NAND function negates the and 
	}
	else if (t == "OR") {
		return max(input1->getValue(), input2->getValue()); //this is the opposite of the AND function, it returns the max
	}
	else if (t == "NOR"){

		if (input1->getValue() == 0.5 || input2->getValue() == 0.5) { //this is the negation of OR
			if (input1->getValue() == 1.0 || input2->getValue() == 1.0) {
				return 0;
			}
			else {
				return 0.5;
			}
		}
		else {
			return negateVal(max(input1->getValue(), input2->getValue()));
		}
	}
	else if (t == "XOR") {//the exclusive OR is not a min or max, so we hard coded it 
		if (input1->getValue() == input2->getValue()) {
			return 0.0;
		}
		else {
			if (input1->getValue() == 1 || input2->getValue() == 1) {
				return 1.0;
			}
			else {
				return 0.5;
			}
		}
	}
	else if (t == "XNOR") {//negation of XOR
		double num;
		if (input1->getValue() == input2->getValue()) {
			num = 0.0;
		}
		else {
			if (input1->getValue() == 1 || input2->getValue() == 1) {
				num = 1.0;
			}
			else {
				num = 0.5;
			}
		}
		return negateVal(num);

	}
	else if (t == "NOT") {//we negate the values
		if (input1->getValue() == 1) {
			return 0.0;
		}
		else if (input1->getValue() == 0) {
			return 1.0;
		}
		else {
			return 0.0;
		}
		
	}

	return 0.0;
}
