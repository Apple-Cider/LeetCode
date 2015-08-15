#include "solution.hpp"

std::string Solution::longestPalindrome(std::string s) {
	if (s.length() < 2) { return s; }

	str = s;
	std::string::iterator right = str.begin(),
		left = str.begin();
	longestBegin = str.begin();
	longestEnd = str.begin();

	while (++right != str.end()) {
		if (*left == *right) {
			checkPalindrome(right, left);
		}
		if (left != str.begin()) {
			--left;
			if (*left == *right) {
				checkPalindrome(right, left);
			}
		}
		left = right;
	}
	

	return std::string(longestBegin, longestEnd);
}

void Solution::checkPalindrome(
	std::string::iterator right,
	std::string::iterator left) {

	while ((left != str.begin())
		&& (right != (str.end() - 1))
		&& *left == *right) {
		--left; ++right;
	}

	//broke while loop because beginning/end of str reached
	if (*left != *right) {
		++left; --right;
	}

	if ((right - left + 1) > (longestEnd - longestBegin)) {
		longestEnd = right + 1;
		longestBegin = left;
	}
}