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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        int count = 0;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }
        if (count < k)
            return head;

        ListNode* prev = nullptr;
        ListNode* node = head;
        for (int i = 0; i < k; i++) {
            ListNode* temp = node->next;
            node->next = prev;
            prev = node;
            node = temp;
        }
        head->next = reverseKGroup(node, k);
        return prev;
    }
};
