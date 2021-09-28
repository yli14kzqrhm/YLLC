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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> mystack;
        TreeNode* ptr = root;
        
        while (ptr || !mystack.empty()) {
            while (ptr) {
                mystack.push(ptr);
                ptr = ptr->left;
            }
            
            ptr = mystack.top();
            ans.push_back(ptr->val);
            mystack.pop();
            ptr = ptr->right;
        }

        return ans;
    }

};