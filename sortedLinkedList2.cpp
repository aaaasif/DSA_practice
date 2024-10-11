#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Modified function to merge two sorted lists recursively
ListNode* mergeSortedListsRecursive(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) return list2;
    if (list2 == nullptr) return list1;

    if (list1->val <= list2->val) {
        list1->next = mergeSortedListsRecursive(list1->next, list2);
        return list1;
    } else {
        list2->next = mergeSortedListsRecursive(list1, list2->next);
        return list2;
    }
}

// Helper function to print a list
void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

// Helper function to create a list from an array
ListNode* createList(const int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;
    for (int i = 1; i < size; ++i) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }
    return head;
}

int main() {
    int arr1[] = {1, 4, 7, 9, 10};
    int arr2[] = {5, 6, 8};
    ListNode* list1 = createList(arr1, 5);
    ListNode* list2 = createList(arr2, 3);

    cout << "List 1: ";
    printList(list1);
    cout << "List 2: ";
    printList(list2);
    ListNode* mergedListRecursive = mergeSortedListsRecursive(list1, list2);
    cout << "\nMerged List (Recursive): ";
    printList(mergedListRecursive);

    return 0;
}
