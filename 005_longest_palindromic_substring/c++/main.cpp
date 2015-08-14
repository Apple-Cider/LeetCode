#include <string>
#include <iostream>
#include "solution.hpp"

void test();

int main(int argc, char** argv) {
	char anotherTest = 'y';
	while (anotherTest == 'y') {
		test();
		std::cout << "want another test? (y/n) ";
		std::cin >> anotherTest;
	}
	return 0;
}

void test() {
	std::string s, answer, computedAnswer;
	std::cout << "input test string " << std::endl
		<< "(type empty for \"\"): ";
	std::cin >> s;

	if (s == "empty") { s = ""; }
	else {
		std::cout << "input expected answer: ";
		std::cin >> answer;
	}

	Solution solution;
	computedAnswer = solution.longestPalindrome(s);
	std::cout << "  the computed answer: " << computedAnswer << std::endl;
}