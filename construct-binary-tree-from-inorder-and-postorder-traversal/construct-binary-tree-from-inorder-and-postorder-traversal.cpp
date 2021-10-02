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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) {
            return NULL;
        }
        
        int i;
        
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        
        for (i = 0; i < inorder.size(); i++) {
            if (inorder[i] == root->val) {
                break;
            }
        }
        
        vector<int> inorderleft(inorder.begin(), inorder.begin() + i);
        vector<int> inorderright(inorder.begin() + i + 1, inorder.end());
        vector<int> postorderleft(postorder.begin(), postorder.begin() + i);
        vector<int> postorderright(postorder.begin() + i, postorder.end() - 1);
        
        root->left = buildTree(inorderleft, postorderleft);
        root->right = buildTree(inorderright, postorderright);
        return root;
    }
};