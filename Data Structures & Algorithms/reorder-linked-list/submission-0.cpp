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
public:
    void reorderList(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        // head -> 0 -> 1 -> 2 -> slow -> 3 , fast -> 4 -> 5 -> 6
        ListNode* prev = nullptr;
        while (fast != nullptr){
            ListNode* temp = fast->next;
            fast->next = prev;
            prev = fast;
            fast = temp;
        }
        // merge the two list 1 then list 2
        ListNode* dummy = head;
        ListNode* dummy2 = prev;
        while(dummy2){
            ListNode* temp1 = dummy->next;
            ListNode* temp2 = dummy2->next;
            dummy->next = dummy2;
            dummy2->next = temp1;
            dummy = temp1;
            dummy2 = temp2;
        }
    }
};
