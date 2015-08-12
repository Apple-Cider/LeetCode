#include <string>
#include "solution.hpp"

int main(int argc, char** argv) {
	std::string myString = "abcabcbb";
	int longest = Solution::lengthOfLongestSubstring(myString);

	return 0;
	//std::string myString = "chbacagibecaieadeaaeabehe";
}