#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if (root != nullptr){
            DFS(ans, root, 0);
        }
        
        return ans;
    }
    
    void DFS(vector<vector<int>> & input, TreeNode* root, int level){
        
        if (root != nullptr) {
            int input_level = input.size();
            if (input_level <= level) {
                input.push_back(vector<int>());
            }
            input.at(level).push_back(root->val);

            DFS(input, root->left, level + 1);
            DFS(input, root->right, level + 1);
        }
        
    }
    
};
