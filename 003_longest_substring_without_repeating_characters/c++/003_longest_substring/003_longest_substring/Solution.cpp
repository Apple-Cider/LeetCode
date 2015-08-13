#include "solution.hpp"

int Solution::lengthOfLongestSubstring(std::string s) {
	std::string longestSubstring = Solution::longestSubstring(s);
	return longestSubstring.length();
}

std::string Solution::longestSubstring(std::string s) {
	if (s.length() < 2) { return s; }

	longestSubstrBegin = s.begin();
	longestSubstrEnd = s.begin();

	std::string::iterator substrBegin = s.begin(),
		substrEnd = s.begin();
	
	while (++substrEnd != s.end()) {
		checkNextChar(substrBegin, substrEnd);
	}

	handleLastSubstr(substrBegin, substrEnd);

	std::string longestString = std::string(longestSubstrBegin, longestSubstrEnd);
	return longestString;
}


std::string::iterator Solution::firstLocationOf(std::string::iterator checker, char target) {
	while (*checker != target) { ++checker; }
	return checker;
}

void Solution::checkNextChar(std::string::iterator& start, std::string::iterator next) {
	char nextChar = *next;
	std::string::iterator firstLocationOf = Solution::firstLocationOf(start, nextChar);

	//if nextChar appears before its latest location, stop
	//  lengthening the substring and test its length vs
	//  the current longest substring
	if (firstLocationOf != next) {
		Solution::handleNewSubstr(start, firstLocationOf, next);
	}
}

void Solution::handleNewSubstr(std::string::iterator& start, std::string::iterator duplicate, std::string::iterator end) {
	int substrLength = end - start,
		longestSubstrLength = longestSubstrEnd - longestSubstrBegin;

	if (substrLength > longestSubstrLength) {
		longestSubstrBegin = start;
		longestSubstrEnd = end;
	}

	start = duplicate + 1;
}

void Solution::handleLastSubstr(std::string::iterator start, std::string::iterator end) {
	int substrLength = end - start,
		longestSubstrLength = longestSubstrEnd - longestSubstrBegin;
	if (substrLength > longestSubstrLength) {
		longestSubstrBegin = start;
		longestSubstrEnd = end;
	}
}