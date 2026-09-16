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

Node* rotateRight(Node* head, int k) {

    // Empty list or single node
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    // Find length and last node
    int n = 1;
    Node* tail = head;

    while (tail->next != nullptr) {
        tail = tail->next;
        n++;
    }

    // Remove unnecessary rotations
    k = k % n;

    if (k == 0) {
        return head;
    }

    // Make the list circular
    tail->next = head;

    // Find new tail
    int stepsToNewTail = n - k - 1;

    Node* newTail = head;

    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // New head comes after new tail
    Node* newHead = newTail->next;

    // Break the circle
    newTail->next = nullptr;

    return newHead;
}

void printList(Node* head) {

    while (head != nullptr) {

        cout << head->data;

        if (head->next != nullptr) {
            cout << " → ";
        }

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

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = rotateRight(head, k);

    cout << "Rotated list: ";
    printList(head);

    return 0;
}