ListNode* mergeTwoListsIterative(ListNode* l1, ListNode* l2) {

    ListNode dummy(0);
    ListNode* current = &dummy;
    while (l1 != nullptr && l2 != nullptr) {

        if (l1->val <= l2->val) {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }


    if (l1 != nullptr) {
        current->next = l1;
    } else {
        current->next = l2;
    }

    return dummy.next;
}
