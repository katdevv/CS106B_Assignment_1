/*
 * File: ConsecutiveHeads.cpp
 * --------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Consecutive Heads problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include "random.h"
#include <vector>
#include <string>

using namespace std;

bool threeHeads(vector<string>& flips) {
	// Check if there are 3 consecutive heads
	int count = 0;
	for (size_t i = 0; i < flips.size(); i++) {
		if (flips[i] == "heads") {
			count++;
			if (count == 3) return true;
		}
		else count = 0;
	}
	return count == 3;
}

string coin() {
	// Simulation
	return randomChance(0.5) ? "heads" : "tails";
}

int main() {
	// Remember the coins
	vector <string> flips = {};

	// Flip the coins
	while (!threeHeads(flips)) {
		string flip = coin();
		flips.push_back(flip);
		cout << flip << endl;
	}

	cout << "it took " << flips.size() << " flips to get 3 consecutive heads." << endl;
	return 0;
}