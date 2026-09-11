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

Node* removeDuplicates(Node* head) {

    if (head == nullptr) {
        return head;
    }

    Node* current = head;

    while (current != nullptr &&
           current->next != nullptr) {

        if (current->data == current->next->data) {

            Node* duplicate = current->next;

            current->next = current->next->next;

            delete duplicate;
        }
        else {

            current = current->next;
        }
    }

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

    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    cout << "After removing duplicates: ";
    printList(head);

    return 0;
}