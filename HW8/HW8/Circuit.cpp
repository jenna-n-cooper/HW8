#include "Circuit.h"

Circuit::Circuit(int numline)
{
	inputs.resize(numline);
	outputs.resize(numline);
	wires.resize(numline);
	gates.resize(numline);
}
