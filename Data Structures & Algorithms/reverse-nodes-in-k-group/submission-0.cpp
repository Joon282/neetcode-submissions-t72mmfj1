ListNode* reverseKGroup(ListNode* head, int k) {
    // Check if k nodes remain
    ListNode* curr = head;
    int count = 0;
    while (curr && count < k) {
        curr = curr->next;
        count++;
    }
    
    // Not enough nodes → return unchanged
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