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
        ListNode* node = head;
        int size  = 0;
        while (node != nullptr){
            node = node->next;
            size++;
        }
        int index = size - n;
        if (index == 0){
            return nullptr;
        }
        ListNode* dummy = head;
        for (int i = 1; i < index; i++){
            dummy = dummy->next;
        }
        ListNode* curr = dummy->next;
        dummy->next = curr->next;
        curr->next = nullptr;
        return head;
    }
};
