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
    int minDiffInBST(TreeNode* root) {
        vector<int> tmp;
        
        inordertraverse(root, tmp);
        
        int ans = tmp[1] - tmp[0];
        int diff;
        
        for (int i = 1; i < tmp.size() - 1; i++) {
            diff = tmp[i+1] - tmp[i];
            if (ans > diff) {
                ans = diff;
            }
        }
        return ans;
    }
    
    void inordertraverse(TreeNode* root, vector<int>& tmp) {
        if (!root) {
            return ;
        }
        
        inordertraverse(root->left, tmp);
        tmp.push_back(root->val);
        inordertraverse(root->right, tmp);
    }
};