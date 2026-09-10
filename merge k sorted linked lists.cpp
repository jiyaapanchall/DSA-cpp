#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = nullptr;
    }
};

struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {

    priority_queue<
        ListNode*,
        vector<ListNode*>,
        Compare
    > minHeap;

    // Put first node of every list into heap
    for (ListNode* head : lists) {

        if (head != nullptr) {
            minHeap.push(head);
        }
    }

    // Dummy node
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;

    while (!minHeap.empty()) {

        // Get smallest node
        ListNode* current = minHeap.top();
        minHeap.pop();

        // Add it to result
        tail->next = current;
        tail = current;

        // Add next node from same list
        if (current->next != nullptr) {
            minHeap.push(current->next);
        }
    }

    return dummy->next;
}

void printList(ListNode* head) {

    while (head != nullptr) {
        cout << head->val << " ";

        head = head->next;
    }

    cout << endl;
}

int main() {

    // List 1
    ListNode* a = new ListNode(1);
    a->next = new ListNode(4);
    a->next->next = new ListNode(7);

    // List 2
    ListNode* b = new ListNode(2);
    b->next = new ListNode(5);
    b->next->next = new ListNode(8);

    // List 3
    ListNode* c = new ListNode(3);
    c->next = new ListNode(6);
    c->next->next = new ListNode(9);

    vector<ListNode*> lists = {a, b, c};

    ListNode* result = mergeKLists(lists);

    cout << "Merged list: ";
    printList(result);

    return 0;
}