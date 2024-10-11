#include <bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;              
    ListNode *next;     

    ListNode(int x) : val(x), next(nullptr) {} 
};


struct NodeCompare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; 
    }
};


ListNode* mergeMultipleLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, NodeCompare> minHeap;

  
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode dummy(0);  
    ListNode* current = &dummy;  

    while (!minHeap.empty()) {
        ListNode* smallestNode = minHeap.top();
        minHeap.pop();
        current->next = smallestNode;
        current = current->next;
        if (smallestNode->next) {
            minHeap.push(smallestNode->next);
        }
    }

    return dummy.next; 
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "nullptr" << endl;  
}

int main() {
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);

    ListNode* list3 = new ListNode(2);
    list3->next = new ListNode(6);

    vector<ListNode*> lists = {list1, list2, list3};

    ListNode* mergedList = mergeMultipleLists(lists);

    printList(mergedList);

    return 0;
}
