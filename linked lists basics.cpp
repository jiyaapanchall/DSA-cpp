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

int main() {

    // Create nodes
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);

    // Connect nodes
    head->next = second;
    second->next = third;
    third->next = fourth;

    // Traverse the linked list
    Node* current = head;

    while (current != nullptr) {

        cout << current->data << " ";

        current = current->next;
    }

    return 0;
}