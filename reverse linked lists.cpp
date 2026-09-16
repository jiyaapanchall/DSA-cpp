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

Node* reverseList(Node* head) {

    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {

        // Save next node
        Node* next = current->next;

        // Reverse pointer
        current->next = prev;

        // Move prev forward
        prev = current;

        // Move current forward
        current = next;
    }

    return prev;
}

void printList(Node* head) {

    while (head != nullptr) {

        cout << head->data << " → ";

        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: ";
    printList(head);

    head = reverseList(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}