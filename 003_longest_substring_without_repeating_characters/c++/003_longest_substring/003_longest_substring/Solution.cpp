#include "solution.hpp"

int Solution::lengthOfLongestSubstring(std::string s) {
	if (s.length < 2) { return s.length; }

	int longest = 1;

	std::string::iterator substrBegin = s.begin(),
		substrEnd = s.begin() + 1;

	for (std::string::iterator checker; substrEnd != (s.end() - longest); ++substrEnd) {
		checker = firstLocationOf(substrBegin, *substrEnd);
		if (checker != substrEnd) {
			if (longest < (substrEnd - substrBegin)) {
				longest = substrEnd - substrBegin; 
			}
			substrBegin = checker;
		}
	}

	return longest;
}


std::string::iterator Solution::firstLocationOf(std::string::iterator start, char c) {
	while (*start != c) { ++start; }
	return start;
}