#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution{
	public:
		vector<int> twoSum(vector<int>& nums, int target){
			unordered_map<int,int> indicies;
			int size = nums.size();
			for (int i = 0; i < size; i ++) {
				if(indicies.find(target - nums[i]) != indicies.end()) {
					cout << "result is: " << indicies[target - nums[i]] << ' ' << i << endl;
					return {indicies[target- nums[i]], i};
				}
				indicies[nums[i]] = i;
			}
			return {};
		}
};


int main() {
	Solution b;
	vector<int> t1 = {1, 3, 4, 5, 6};
	int target_1 = 5;
	vector<int> result = b.twoSum(t1, target_1);
	// do extra with it;
}