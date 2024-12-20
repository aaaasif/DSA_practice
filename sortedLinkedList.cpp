#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* mergeSortedLists(ListNode* list1, ListNode* list2) {
    ListNode* placeholder = new ListNode(-1);
    ListNode* current = placeholder;

    while (list1 != nullptr && list2 != nullptr) {
        if (list1->val <= list2->val) {
            current->next = list1;
            list1 = list1->next;
        } else {
            current->next = list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = (list1 != nullptr) ? list1 : list2;  
    return placeholder->next;  
}

void printList(ListNode* node) {
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << " -> ";
        node = node->next;
    }
    cout << endl;
}

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


    ListNode* mergedList = mergeSortedLists(list1, list2);
    cout << "\nMerged List: ";
    printList(mergedList);

    return 0;
}
