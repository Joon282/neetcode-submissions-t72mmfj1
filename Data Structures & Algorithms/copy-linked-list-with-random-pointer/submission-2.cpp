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
        if (!head){
            return nullptr;
        }
        std::unordered_map<Node*, Node*> map1;
        Node* curr = head;
        while(curr){
            Node* newNode = new Node(curr->val); // newNode->val = NULL & newNode->random = NULL
            map1[curr] = newNode; //[{head, newNode}, {head2, newNode2}, ... , ]
            curr = curr->next; 
        }
        curr = head;
        while (curr) {
            map1[curr]->next = map1[curr->next];
            map1[curr]->random = map1[curr->random];
            curr = curr->next;
        }
        return map1[head];
    }
};
