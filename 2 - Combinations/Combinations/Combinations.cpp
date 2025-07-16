/*
 * File: Combinations.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Combinations problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
using namespace std;

int c(int a, int b) {
	// Check if the function "hits the walls of the triangle"
	if (a == 0 || b == 0 || a == b) return 1;

	// Check if the numbers are invalid
	if (a < 0 || b < 0 || a < b) return 0;

	// Calc previous two
	return c(a - 1, b - 1) + c(a - 1, b);
}

int main() {
	cout << c(5, 3) << endl;
	return 0;
}
