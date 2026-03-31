/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
    std::priority_queue<ListNode*, std::vector<ListNode*>, Compare> pq;
        for (const auto& head : lists){
            if (head != nullptr){
                pq.push(head);
            }
        }
        ListNode* head = new ListNode(0); 
        ListNode* dummy = head;
        while (!pq.empty()){ // 1, 1, 3
            ListNode* curr = pq.top();
            dummy->next = curr;
            dummy = dummy->next;
            pq.pop();
            if (curr->next != nullptr){
                pq.push(curr->next);
            }
        }
        return head->next;
    }
};
