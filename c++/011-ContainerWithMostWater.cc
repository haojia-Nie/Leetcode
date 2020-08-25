#inlcude <iostream>
#include <vector>

using namespasce std;

// Things to Notice
/* 
1. Width * Height
Height depends on the shorter one, the width is the index difference

2. Everytime we have a shorter one, we move that, 
If two are the same, move either one is ok

3. Everytime you move inside, the width is shorter by 1 \
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int size = height.size();
        int maxArea = 0; 
        
        int left = 0;
        int right = size - 1;
        
        while (left < right){
            int left_val = height.at(left);
            int right_val = height.at(right);
            int height = (left_val >= right_val) ? right_val : left_val;
            int width = right - left;
            int area = height * width;
            
            if (right_val < left_val){
                right --;
            }
            
            else {
                left ++;
            }

            maxArea = (maxArea > area) ? maxArea : area;
        }
        return maxArea;
    }
};

/*Test Cases:
Input: [1,8,6,2,5,4,8,3,7]
Out: 49
*/
