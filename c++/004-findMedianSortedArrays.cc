#include <iostream>
#include <vector>
using namespace std;

/* description
   two sorted array nums1 and num2 of size m and n
   Find the median of the two sorted arrays.
   The overall run time complexity should be O(log(m+n))
*/

/* Reference: Ideas and algorithm from:
https://leetcode.wang/leetCode-4-Median-of-Two-Sorted-Arrays.html
*/


class Solution {
	public:
		double findMedianSortedArrays(vector<int> & nums1, vector<int> & nums2) {
			int size_1 = nums1.size();
			int size_2 = nums2.size();
			int left = (size_1 + size_2 + 1) / 2;
			int right = (size_1 + size_2 + 2) / 2;

			// combine the even and odd cases
			return  (getKth(nums1, 0, size_1 - 1, 
					nums2, 0, size_2 - 1, left)
				+ getKth(nums1, 0, size_1 - 1, 
					nums2, 0, size_2 - 1, right)) * 0.5;
		}
	private:

		double getKth(vector<int> & nums1, int start1, int end1, 
				vector<int> & nums2, int start2, int end2,
				int k) {
			int len1 = end1 - start1 + 1;
			int len2 = end2 - start2 + 1;
			
			if (len1 > len2) return getKth(nums2, start2, end2,
					nums1, start1, end1, k);
			if (len1 == 0) return nums2[start2 + k - 1];
			if (k == 1) return min(nums1.at(start1), nums2.at(start2));
			
			
			int index1 = start1 + find_min(len1, k / 2) - 1;
			int index2 = start2 + find_min(len2, k / 2) - 1;
			
			if (nums1.at(index1) > nums2.at(index2)) {
				return getKth(nums1, start1, end1, 
						nums2, index2 + 1, end2, 
						k - (index2 - start2 + 1));
			}
			else {
				return getKth(nums1, index1 + 1, end1, 
						nums2, start2, end2, 
						k - (index1 - start1 + 1));
			}
		}
		
		int find_min(int a, int b) {
			if (a < b) return a;
			return b;
		}
	
};

int main() {
	Solution b;
	vector<int> num1 = {1, 2, 4, 6, 9};
	vector<int> num2 = {7, 8, 10, 13, 14};

	double median = b.findMedianSortedArrays(num1, num2);

	cout << "median is: " << median << endl; // output: 7.5
//	num1->clear();
//	num2->clear();

}