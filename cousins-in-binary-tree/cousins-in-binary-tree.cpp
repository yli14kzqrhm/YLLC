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
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_set<int> tmp;
        queue<TreeNode*> q;
        q.push(root);
        int n;
        TreeNode* node;

        while(!q.empty()) {
            n = q.size();
                    
            for (int i = 0; i < n; i++) {
                node = q.front();
                tmp.insert(node->val);
                
                if ((node->left) && 
                    (node->right) && 
                    (((node->left->val == x) && (node->right->val == y)) || 
                     ((node->left->val == y) && (node->right->val == x)))) {
                        return false;
                    }
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
                
                q.pop(); 
            }
            
            
            if ((tmp.find(x) != tmp.end()) && (tmp.find(y) != tmp.end())) {
                return true;
            }
            
            tmp.clear();
        }
        
        return false;
    }
};