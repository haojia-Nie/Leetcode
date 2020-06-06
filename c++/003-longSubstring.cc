//
//  003-longSubstring.cc
//
//
//  Created by Haojia Nie on 2020-06-05.
//
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
	public:
		//Solution 1 --- Brutal Force(embedded for loop)
        // O(n^2)
		int LongestSubstring_basic(string s) {
			int len = s.length();
			int max_len;
			for (int i = 0; i < len; i++) {
				int cur_len = 0;
				for (int j = i; j < len; j++) {
					if (s.at(i) != s.at(j)){
						break;
					}
					cur_len++;
				}
				max_len = cur_len ? cur_len > max_len : max_len;

			}
			return max_len;
		}
	
		// Solution 2 -- kind of like Sliding window
		//   	     -- keep track of the index of the char as well
		// O(n)
        int LongestSubstring_optimize(string s) {
			int len = s.length();
			int max_len = 0;
			unordered_map<string, int> map;
			int cur_len = 0;
			for (int i = 0; i < len; i++) {
				string compare = s.substr(i, 1);
				if(map.find(compare) != map.end()){
					cur_len = i - map[compare];
					map[compare] = i;
				} else {
					map[compare] = i; 
					cur_len ++;
				}
				max_len = (cur_len > max_len) ? cur_len : max_len;
			}
			return max_len;
		}
};


int main() {
	Solution b;
	string t1 = "string";
	string t2 = "ababcded";
	int t1_result = b.LongestSubstring_optimize(t1);
	int t2_result = b.LongestSubstring_optimize(t2);
	cout << t1 << " : " << t1_result << endl; // output: string: 6
	cout << t2 << " : " << t2_result << endl; // output: ababcded: 5
}
