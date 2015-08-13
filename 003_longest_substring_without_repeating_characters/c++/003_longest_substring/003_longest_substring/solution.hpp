#pragma once
#include <string>

class Solution {
public:
	int lengthOfLongestSubstring(std::string);
	std::string longestSubstring(std::string);
	std::string::iterator firstLocationOf(std::string::iterator start, char target);
	void checkNextChar(std::string::iterator& start, std::string::iterator next);
	void handleNewSubstr(std::string::iterator& start, std::string::iterator duplicate, std::string::iterator end);
	void handleLastSubstr(std::string::iterator start, std::string::iterator end);
private:
	std::string::iterator longestSubstrBegin;
	std::string::iterator longestSubstrEnd;
};