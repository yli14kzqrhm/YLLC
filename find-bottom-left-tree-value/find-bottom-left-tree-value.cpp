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
    int findBottomLeftValue(TreeNode* root) {
        vector<int> row;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        int n, ans;
        TreeNode* ptr;
        
        while (!myqueue.empty()) {
            n = myqueue.size();
            
            ans = myqueue.front()->val;

            for (int i = 0; i < n; i++) {
                ptr = myqueue.front();
                
                if (ptr->left) {
                    myqueue.push(ptr->left);
                }
                
                if (ptr->right) {
                    myqueue.push(ptr->right);
                }
                
                myqueue.pop();
            }
        }
        
        return ans;
    }
};