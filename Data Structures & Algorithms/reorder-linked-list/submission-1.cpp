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

class Solution {
    // head 2,4,6,8 tail
    // 2 -> 8 -> 4 -> 6 
public:
    void reorderList(ListNode* head) {
        if (!head){
            return;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next){
            fast = fast->next->next;
            slow = slow->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        while (fast){
            ListNode* temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }
        ListNode* curr = head;
        while (prev){
            ListNode* temp1 = curr->next;
            ListNode* temp2 = prev->next;
            curr->next = prev;
            prev->next = temp1;
            curr = temp1;
            prev = temp2;
        }
    }
};
