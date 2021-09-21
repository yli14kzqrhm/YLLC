/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (!root) {
            return root;
        }
        
        vector<Node*> v;
        int n;
        v.push_back(root);
        
        
        while (!v.empty()) {
            n = v.size();
            
            for (int i = 0; i < n; i++) {
                if (i < n - 1) {
                    v[0]->next = v[1];
                }
                
                if (v[0]->left) {
                    v.push_back(v[0]->left);
                }
                
                if (v[0]->right) {
                    v.push_back(v[0]->right);
                }
                
                v.erase(v.begin());
                
            }
        }
        
        return root;
    }
};