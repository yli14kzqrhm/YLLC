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
    void flatten(TreeNode* root) {
        if (!root) {
            return;
        }
        
        TreeNode* ptr = root;
        
        if (ptr->left) {
            TreeNode* tmp = findtherightmost(root->left);
            tmp->right = ptr->right;
            ptr->right = ptr->left;
            ptr->left = NULL;
        }
        
        flatten(ptr->right);
    }
    
    TreeNode* findtherightmost(TreeNode* root) {
        if (!root->right) {
            return root;
        }
        
        return findtherightmost(root->right);
    }
};