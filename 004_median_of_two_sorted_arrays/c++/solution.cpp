#include "solution.hpp"

double Solution::findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	int size = nums1.size() + nums2.size(),
		eltsBehindMedian = (size - 1) / 2,
		medianIdx,
		i = 0,
		j = 0;
	double median;
	bool twoEltsNeeded = (size % 2) == 0;
	
	bool num2ElLarger, medianReached = false;
	while ((i < nums1.size()) && (j < nums2.size())) {
		medianReached = (i + j) == eltsBehindMedian;
		if (medianReached) break;
		num2ElLarger = nums1.at(i) < nums2.at(j);
		if (num2ElLarger) ++i;
		else ++j;
	}

	//median was not reached, therefore an array's end was reached
	if (!medianReached) {
		if (i < nums1.size()) {
			medianIdx = eltsBehindMedian - nums2.size();
			median = (double)nums1.at(medianIdx);
			if (twoEltsNeeded) {
				median += (double)nums1.at(medianIdx + 1);
				median /= 2.0;
			}
		}
		else {
			medianIdx = eltsBehindMedian - nums1.size();
			median = (double)nums2.at(medianIdx);
			if (twoEltsNeeded) {
				median += (double)nums2.at(medianIdx + 1);
				median /= 2.0;
			}
		}

		return median;
	}
	else {
		num2ElLarger = nums1.at(i) < nums2.at(j);
		if (num2ElLarger) {
			median = (double)nums1.at(i);
			++i;
		}
		else {
			median = (double)nums2.at(j);
			++j;
		}

		if (twoEltsNeeded) {
			if (i == nums1.size()) {
				median += (double)nums2.at(j);
			}
			else if (j == nums2.size()) {
				median += (double)nums1.at(i);
			}
			else {
				num2ElLarger = nums1.at(i) < nums2.at(j);
				if (num2ElLarger) {
					median += (double)nums1.at(i);
				}
				else {
					median += (double)nums2.at(j);
				}
			}

			median /= 2.0;
		}

		return median;
	}
}

/*
std::vector<int> Solution::mergeSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::vector<int> merged;
	merged.reserve(nums1.size() + nums2.size());
}
*/