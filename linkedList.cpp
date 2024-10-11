int main() {
    // Create first sorted list: 1 -> 4 -> 7 -> 9 -> 10
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(10);

    // Create second sorted list: 5 -> 6 -> 8
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);

    // Iterative approach
    cout << "Merged List (Iterative): ";
    ListNode* mergedListIterative = mergeTwoListsIterative(l1, l2);
    printList(mergedListIterative);

    // Recursive approach (recreate the lists because they were modified by the iterative approach)
    l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(7);
    l1->next->next->next = new ListNode(9);
    l1->next->next->next->next = new ListNode(10);

    l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(8);

    cout << "Merged List (Recursive): ";
    ListNode* mergedListRecursive = mergeTwoListsRecursive(l1, l2);
    printList(
        
    );

    return 0;
}
