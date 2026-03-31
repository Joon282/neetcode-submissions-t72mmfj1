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
        Node* curr = head;
        std::unordered_map<Node*, Node*> map1;
        map1[nullptr] = nullptr;

        while (curr != nullptr){
            Node* dummy = new Node(curr->val);
            map1[curr] = dummy;
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr){
            Node* dummy = map1[curr];
            dummy->next = map1[curr->next];
            dummy->random = map1[curr->random];
            curr = curr->next;
        } 
        return map1[head];
    }
};
