#pragma once

#include "priorityQueue.h"

using namespace std;


bool operator<(const priorityQueue& p1, const priorityQueue& p2)
{
	// by default the queue is a MAX queue, so we reverse the comparison
// from '<' to '>' (see the return statements) to make it a MIN queue
	if (p1.key == p2.key) {
		return p1.secondaryKey > p2.secondaryKey;
	}

	return p1.key > p2.key;
}