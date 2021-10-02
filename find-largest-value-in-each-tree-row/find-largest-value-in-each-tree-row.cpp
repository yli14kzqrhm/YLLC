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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if (!root) {
            return ans;
        }
        
        queue<TreeNode*> myqueue;
        
        myqueue.push(root);
        int n, max;
        TreeNode* ptr;
        
        while (!myqueue.empty()) {
            n = myqueue.size();
            max = INT_MIN;
            
            for (int i = 0; i < n; i++) {
                ptr = myqueue.front();
                if (max < ptr->val) {
                    max = ptr->val;
                }
                
                if (ptr->left) {
                    myqueue.push(ptr->left);
                }
                if (ptr->right) {
                    myqueue.push(ptr->right);
                }
                myqueue.pop();
            }
            ans.push_back(max);
        }
        return ans;
    }
};