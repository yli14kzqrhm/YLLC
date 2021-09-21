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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        int n;
        double sum = 0.0;
        queue<TreeNode*> q;
        TreeNode* node;
        
        q.push(root);
        
        while (!q.empty()) {
            n = q.size();
            
            for (int i = 0; i < n; i++) {
                node = q.front();
                
                sum += (double)node->val;
                
                q.pop();
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            sum /= (double)n;
            ans.push_back(sum);
            sum = 0.0;
        }
        
        return ans;
    }
};