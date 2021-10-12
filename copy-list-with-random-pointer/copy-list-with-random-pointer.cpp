/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) {
            return NULL;
        }
        Node* ans = new Node(head->val);
        unordered_map<Node*, Node*> map;
        map[head] = ans;
        
        Node* ptr1 = head;
        Node* ptr2 = ans;
        
        while (ptr1->next) {
            ptr2->next = new Node(ptr1->next->val);
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
            map[ptr1] = ptr2;
        }
        
        ptr1 = head;
        ptr2 = ans;
        
        while (ptr1) {
            ptr2->random = map[ptr1->random];
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ans;
    }
};