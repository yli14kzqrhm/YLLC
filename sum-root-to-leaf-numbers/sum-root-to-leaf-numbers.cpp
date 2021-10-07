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
    int ans;
    int sumNumbers(TreeNode* root) {
        ans = 0;
        helper(root, 0);
        return ans;
    }
    
    void helper(TreeNode* root, int sum) {
        if (!root) {
            return ;
        }
        
        sum = sum * 10 + root->val;
        
        if (!root->left && !root->right) {
            ans += sum;
            return ;
        }


        helper(root->left, sum);

        helper(root->right, sum);
    }
};