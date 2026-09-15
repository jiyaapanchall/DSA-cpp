#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

Node* removeNthFromEnd(Node* head, int n) {

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* fast = dummy;
    Node* slow = dummy;

    // Move fast n steps ahead
    for (int i = 0; i < n; i++) {
        fast = fast->next;
    }

    // Move both pointers
    while (fast->next != nullptr) {
        fast = fast->next;
        slow = slow->next;
    }

    // Remove the target node
    Node* nodeToDelete = slow->next;
    slow->next = slow->next->next;

    delete nodeToDelete;

    Node* newHead = dummy->next;

    delete dummy;

    return newHead;
}

void printList(Node* head) {

    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    int n = 2;

    cout << "Original list: ";
    printList(head);

    head = removeNthFromEnd(head, n);

    cout << "After deletion: ";
    printList(head);

    return 0;
}