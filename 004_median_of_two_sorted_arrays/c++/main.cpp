#include <iostream>
#include <vector>
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
	std::vector<int> v0, v1;
	int nextInt;
	double answer, computedAnswer;

	std::cout << "input 1st array ints ('-1' terminates): " << std::endl;

	while (std::cin >> nextInt) {
		if (nextInt == -1) break;
		v0.push_back(nextInt);
	}
	
	std::cout << "input 2nd array ints ('-1' terminates): " << std::endl;

	while (std::cin >> nextInt) {
		if (nextInt == -1) break;
		v1.push_back(nextInt);
	}

	std::cout << "input expected answer: ";
	std::cin >> answer;

	Solution solution;
	computedAnswer = solution.findMedianSortedArrays(v0, v1);
	std::cout << "  the computed answer: " << computedAnswer << std::endl;
}