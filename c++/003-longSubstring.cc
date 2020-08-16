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

	// Solution 3;
	// use hash Table to keep track of the index, and if the char is already in hash table, then it's a duplicate
	int lengthOfLongestSubstring(string s) {
		// create hash table
		int len = s.length();
		int result = 0;
		map <char, int> hashTable;
		int cur_result = 0;
		int start_index = 0;
		 
		for (int i = 0; i < len; i ++){     
		    char at = s[i];
		    int orig_index = hashTable[at];
		    if (orig_index == 0){
			hashTable[at] = i + 1;
			cur_result ++;
		    }
		    else if (orig_index != 0){  
			if ((orig_index - 1) < start_index){
			    cur_result ++;
			    hashTable[at] = i + 1;
			}
			else {
			    cur_result = (i + 1) - orig_index;
			    start_index = orig_index;
			}
			hashTable[at] = i + 1;
		    }
		    result = (cur_result > result) ? cur_result : result;      
		}
		return result;
		      
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
