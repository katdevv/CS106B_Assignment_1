/*
 * File: FleschKincaid.cpp
 * ----------------------
 * Name: [TODO: enter name here]
 * Section: [TODO: enter section leader here]
 * This file is the starter project for the Flesch-Kincaid problem.
 * [TODO: rewrite the documentation]
 */

#include <iostream>
#include "console.h"
#include <fstream>
#include "tokenscanner.h"

using namespace std;

const float c0 = -15.59;
const float c1 = 0.39;
const float c2 = 11.8;

int countSyllables(string s);
float fleschKincaid(string inputFile);

string punctuationMarks[] = { ".", ",", "!", "?", ";", ":", "(", ")", "[", "]", "{", "}", "\"", "'", "_" };

int main() {
	cout << fleschKincaid("1984.txt") << endl;
	return 0;
}

float fleschKincaid(string inputFile) {
	// File
	ifstream ifs(inputFile);
	TokenScanner scanner(ifs);

	// Parameters
	scanner.ignoreWhitespace();
	scanner.addWordCharacters("-'");

	// Variables
	float sentences = 0;
	float words = 0;
	float syllables = 0;

	// Tokenizing
	while (scanner.hasMoreTokens()) {
		string token = scanner.nextToken();
		TokenType tokenType = scanner.getTokenType(token);

		if (token == "." || token == "!" || token == "?" || token == ";") {
			sentences++;
		}
		else if (tokenType == WORD) {
			words++;
			syllables += countSyllables(token);
		}
	}

	ifs.close();

	// For testing
	cout << "Words: " << words << endl;
	cout << "Sentences: " << sentences << endl;
	cout << "Syllables: " << syllables << endl;

	return c0 + c1 * (words / sentences) + c2 * (syllables / words);
}

int countSyllables(string s) {
	int count = 0;
	bool prevVowel = false;

	for (int i = 0; i < s.length(); i++) {
		char c = tolower(s[i]);

		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {

			// 'e' at the end
			if (c == 'e' && i == s.length() - 1) {
				prevVowel = false;
			}

			// 2 vowels in a row
			else if (!prevVowel) {
				count++;
				prevVowel = true;
			}
		}
		else {
			prevVowel = false;
		}
	}

	return count > 0 ? count : 1;
}