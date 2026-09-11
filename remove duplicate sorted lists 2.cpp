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

Node* deleteDuplicates(Node* head) {

    // Dummy node helps when duplicates start from head
    Node* dummy = new Node(0);
    dummy->next = head;

    Node* prev = dummy;
    Node* current = head;

    while (current != nullptr) {

        // Check if current is part of a duplicate group
        if (current->next != nullptr &&
            current->data == current->next->data) {

            int duplicateValue = current->data;

            // Skip all nodes with duplicate value
            while (current != nullptr &&
                   current->data == duplicateValue) {

                Node* temp = current;
                current = current->next;
                delete temp;
            }

            // Connect previous unique node
            prev->next = current;
        }
        else {

            // Current value is unique
            prev = current;
            current = current->next;
        }
    }

    Node* result = dummy->next;

    delete dummy;

    return result;
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
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = deleteDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}