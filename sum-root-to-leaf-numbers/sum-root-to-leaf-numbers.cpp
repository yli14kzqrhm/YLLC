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
    int sumNumbers(TreeNode* root) {
        int ans = 0;
        
        ans = helper(root, ans);
        
        return ans;
    }
    
    int helper(TreeNode* root, int ans) {
        int res = 0;
        
        ans = ans * 10 + root->val;
        
        if (root->left) {
            res += helper(root->left, ans);
        }
        
        if (root->right) {
            res += helper(root->right, ans);
        }
        
        return max(ans,res);
    }
};