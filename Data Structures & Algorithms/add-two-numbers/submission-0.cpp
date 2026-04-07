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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        long long num1 = 0, num2 = 0, count = 0;
        while (l1 != nullptr) {
            num1 += (long long)std::pow(10, count++) * l1->val;
            l1 = l1->next;
        }
        count = 0;
        while (l2 != nullptr) {
            num2 += (long long)std::pow(10, count++) * l2->val;
            l2 = l2->next;
        }
        long long sum = num1 + num2;
        if (sum == 0) return new ListNode(0);
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        while (sum > 0) {
            curr->next = new ListNode(sum % 10);  
            curr = curr->next;
            sum /= 10;
        }
        return head->next;
    }
};
