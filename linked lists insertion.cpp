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

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {

    Node* newNode = new Node(value);

    newNode->next = head;
    head = newNode;
}

// Insert at end
void insertAtEnd(Node*& head, int value) {

    Node* newNode = new Node(value);

    // If list is empty
    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* current = head;

    while (current->next != nullptr) {
        current = current->next;
    }

    current->next = newNode;
}

// Insert at position
void insertAtPosition(Node*& head, int value, int position) {

    // Position 1 means beginning
    if (position == 1) {
        insertAtBeginning(head, value);
        return;
    }

    Node* newNode = new Node(value);
    Node* current = head;

    // Reach node before required position
    for (int i = 1; i < position - 1 && current != nullptr; i++) {
        current = current->next;
    }

    // Invalid position
    if (current == nullptr) {
        cout << "Invalid position!" << endl;
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Print linked list
void printList(Node* head) {

    Node* current = head;

    while (current != nullptr) {
        cout << current->data << " → ";
        current = current->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = nullptr;

    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    insertAtEnd(head, 30);
    insertAtEnd(head, 40);

    cout << "Original list: ";
    printList(head);

    insertAtPosition(head, 25, 3);

    cout << "After inserting 25 at position 3: ";
    printList(head);

    return 0;
}