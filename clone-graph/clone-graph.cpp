/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    unordered_map<int, Node*> MAP;
    Node* cloneGraph(Node* node) {
        if (!node) {
            return NULL;
        }
        
        Node* head = new Node(node->val);
        MAP[head->val] = head;
        
        for (int i = 0; i < node->neighbors.size(); i++) {
            Node* ptr = node->neighbors[i];
            if (MAP.find(ptr->val) == MAP.end()) {
                head->neighbors.push_back(cloneGraph(ptr));
            } else {
                head->neighbors.push_back(MAP[ptr->val]);
            }
            
        }
        
        return head;
    }
};