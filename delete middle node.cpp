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

Node* deleteMiddle(Node* head) {

    // If only one node exists
    if (head == nullptr || head->next == nullptr) {
        return nullptr;
    }

    Node* slow = head;
    Node* fast = head;
    Node* prev = nullptr;

    while (fast != nullptr &&
           fast->next != nullptr) {

        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // slow is the middle node
    prev->next = slow->next;

    delete slow;

    return head;
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

    cout << "Original list: ";
    printList(head);

    head = deleteMiddle(head);

    cout << "After deleting middle: ";
    printList(head);

    return 0;
}