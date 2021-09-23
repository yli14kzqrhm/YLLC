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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        
        if (!root) {
            return ans;
        }
        
        string s = to_string(root->val);
        
        helper(root, ans, s);
        
        return ans;
    }
    
    void helper(TreeNode* root, vector<string>& num, string s) {
        if (!root->left && !root->right) {
            num.push_back(s);
            return;
        }
        
        if (root->left) {
            helper(root->left, num, s + "->" + to_string(root->left->val));
        }
        
        if (root->right) {
            helper(root->right, num, s + "->" + to_string(root->right->val));
        }
        
    }
};