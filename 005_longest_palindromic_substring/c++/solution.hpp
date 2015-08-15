#pragma once
#include <string>

class Solution {
public:
	std::string longestPalindrome(std::string s);
	void checkPalindrome(std::string::iterator right, std::string::iterator left);
private:
	std::string str;
	std::string::iterator longestBegin;
	std::string::iterator longestEnd;
};