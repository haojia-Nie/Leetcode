#include <vector>
#include <iostream>
#include <string>

using namepsace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        addBracket(ans, "", 0, 0, n);
        return ans;
    }
    
    void addBracket(vector<string> & ans, string current, int left, int right, int n){

        if (current.length() == (2 * n)){
            ans.push_back(current);
        }
        
        if (left < n){
            addBracket(ans, current + "(", left + 1, right, n);
        }
        
        if (right < left){
            addBracket(ans, current + ")", left, right + 1, n);
        }
    }
    
};
