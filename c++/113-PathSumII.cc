#include <vector>
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        vector<int> cur_vector;
        
        
        if (root != nullptr){
            DFS(ans, cur_vector, root, 0, sum);
        }
        return ans;
    }
    
    void DFS(vector<vector<int>> & input, vector<int> & cur_sum, TreeNode* cur_root,
             int vector_sum, int sum){
        
        if (cur_root != nullptr) {
            int cur_value = cur_root->val;
            //cout << cur_value << endl;
            
            if (vector_sum + cur_value == sum && (!cur_root->left && !cur_root->right)){
                
                cur_sum.push_back(cur_value);
                input.push_back(cur_sum);
                cur_sum.pop_back();
            }
            
            else {
                vector_sum += cur_value;
                cur_sum.push_back(cur_value);
                vector<int> keep_cur_sum;
                for (int i = 0 ; i < cur_sum.size(); i ++){
                    keep_cur_sum.push_back(cur_sum.at(i));
                }            
                DFS(input, cur_sum, cur_root->left, vector_sum, sum);
                DFS(input, keep_cur_sum, cur_root->right, vector_sum, sum);
            }
        }   
    }
};
