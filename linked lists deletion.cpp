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

// Delete first node
void deleteFromBeginning(Node*& head) {

    if (head == nullptr) {
        return;
    }

    Node* temp = head;

    head = head->next;

    delete temp;
}

// Delete last node
void deleteFromEnd(Node*& head) {

    if (head == nullptr) {
        return;
    }

    // Only one node
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;

    // Reach second-last node
    while (current->next->next != nullptr) {
        current = current->next;
    }

    delete current->next;

    current->next = nullptr;
}

// Delete node at a position
void deleteAtPosition(Node*& head, int position) {

    if (head == nullptr) {
        return;
    }

    // Delete first node
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }

    Node* current = head;

    // Reach node before target
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // Invalid position
    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = current->next;

    current->next = temp->next;

    delete temp;
}

// Print list
void printList(Node* head) {

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " → ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main() {

    // Create linked list
    Node* head = new Node(10);

    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: ";
    printList(head);

    // Delete first
    deleteFromBeginning(head);

    cout << "After deleting first node: ";
    printList(head);

    // Delete last
    deleteFromEnd(head);

    cout << "After deleting last node: ";
    printList(head);

    // Delete position 2
    deleteAtPosition(head, 2);

    cout << "After deleting position 2: ";
    printList(head);

    return 0;
}