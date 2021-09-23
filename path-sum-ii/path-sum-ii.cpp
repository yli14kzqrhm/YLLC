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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        
        if (!root) {
            return ans;
        }
        
        vector<int> tmp;
        
        helper(root, targetSum, ans, tmp);
        
        return ans;
    }
    
    void helper(TreeNode* root, int targetSum, vector<vector<int>>& ans,                         vector<int> tmp) {
        tmp.push_back(root->val);
        
        if (!root->left && !root->right && (root->val == targetSum)) {
            ans.push_back(tmp);
            return ;
        }

        targetSum -= root->val;
        
        if (root->left) {
            helper(root->left, targetSum, ans, tmp);
        }
        
        if (root->right) {
            helper(root->right, targetSum, ans, tmp);
        }
    }
};