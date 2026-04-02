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
        Node* newList = new Node(0);
        Node* dummy = newList;
        while (curr != nullptr){
            dummy->next = new Node(curr->val);
            map1[curr] = dummy->next; 
            curr = curr->next;
            dummy = dummy->next;
        }
        curr = head;
        dummy = newList->next;
        while (curr != nullptr){
            dummy->random = map1[curr->random];
            curr = curr->next;
            dummy = dummy->next;
        }
        return newList->next;
    }
};
