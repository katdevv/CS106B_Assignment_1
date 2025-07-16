/*
 * File: NumericConversions.cpp
 * ---------------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Numeric Conversions problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include <string>
#include "console.h"
using namespace std;

/* Function prototypes */

string intToString(int n);
int stringToInt(string str);
int stringToIntReq(string str);
string intToStringReq(int n);

/* Main program */

int main() {
	cout << stringToInt("4232412") << endl;
	cout << intToString(-4232412) << endl;
	return 0;
}

// Int to String
string intToString(int n) {
	// Check for the 0 and negative cases
	if (n == 0) return "0";
	if (n < 0) return "-" + intToStringReq(n * (-1));

	return intToStringReq(n);
}

// Recursive functionality
string intToStringReq(int n) {
	if (n == 0) return "";
	return intToStringReq(n / 10) + char(n % 10 + '0');
}


// String to Int
int stringToInt(string str) {
	// Check if the string has a negative sign and follow through without it
	if (str[0] == '-') return (-1) * stringToIntReq(str.substr(1, str.size()));

	return stringToIntReq(str);
}

// Recursive functionality
int stringToIntReq(string str) {
	if (str.size() == 1) return str[0] - '0';
	return stringToIntReq(str.substr(0, str.size() - 1)) * 10 + (str[str.size() - 1] - '0');
}