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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (!head){
            return nullptr;
        }
        int m = 0;
        ListNode* size = head;
        while (size){
            size = size->next;
            m++;
        }
        int index = m - n;
        if (index == 0){
            return head->next;
        }
        ListNode* curr = head;
        for (int i = 0; i < index - 1; i++){
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};
