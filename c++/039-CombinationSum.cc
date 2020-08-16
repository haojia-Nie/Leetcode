#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int size_v = candidates.size();
        vector<vector<int>> ans;
        for (int i = 0; i < size_v; i ++){
            int j = i;
            int cur_sum = candidates.at(i);
            vector<int> sum ;
            sum.push_back(cur_sum);
            if (cur_sum == target) {
                ans.push_back(sum);
                continue;
            }
            
            while (j < size_v) {
                int j_value = candidates.at(j);
                int sum_now = j_value + cur_sum;
                if (sum_now < target){
                    sum.push_back(j_value);
                    cur_sum += j_value;
                    //j++;
                }
                else if (sum_now == target){
                    sum.push_back(j_value);
                    ans.push_back(sum);
                    if (sum.size() > 2) {
                        int back = sum.back();
                        cur_sum -= back;
                        sum.pop_back();
                        back = sum.back();
                        cur_sum -= back;   
                        sum.pop_back();
                    }
                    else {
                        break;
                    }  
                }
                else {
                    if (sum.size() > 2) { 
                        int back = sum.back();
                        cur_sum -= back;
                        sum.pop_back();            
                        j += 1;
                    }
                    
                    else {
                        break;
                    }
                }
            }
        }
        return ans;
        
    }
};
