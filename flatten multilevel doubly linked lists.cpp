#include <iostream>
using namespace std;

struct Node {

    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node(int value) {
        val = value;
        prev = nullptr;
        next = nullptr;
        child = nullptr;
    }
};

Node* flatten(Node* head) {

    if (head == nullptr) {
        return head;
    }

    Node* current = head;

    while (current != nullptr) {

        // If there is no child, move forward
        if (current->child == nullptr) {
            current = current->next;
            continue;
        }

        // Save the original next node
        Node* nextNode = current->next;

        // Flatten the child list
        Node* childHead = flatten(current->child);

        // Connect current to child
        current->next = childHead;
        childHead->prev = current;

        // Child pointer is no longer needed
        current->child = nullptr;

        // Find the tail of the flattened child list
        Node* childTail = childHead;

        while (childTail->next != nullptr) {
            childTail = childTail->next;
        }

        // Connect child tail to original next
        if (nextNode != nullptr) {

            childTail->next = nextNode;
            nextNode->prev = childTail;
        }

        // Continue
        current = current->next;
    }

    return head;
}

void printList(Node* head) {

    Node* current = head;

    while (current != nullptr) {

        cout << current->val;

        if (current->next != nullptr) {
            cout << " ⇄ ";
        }

        current = current->next;
    }

    cout << endl;
}

int main() {

    Node* head = new Node(1);

    Node* second = new Node(2);
    Node* third = new Node(3);
    Node* fourth = new Node(4);

    head->next = second;
    second->prev = head;

    second->next = third;
    third->prev = second;

    third->next = fourth;
    fourth->prev = third;

    // Child list: 7 ⇄ 8 ⇄ 9
    Node* seven = new Node(7);
    Node* eight = new Node(8);
    Node* nine = new Node(9);

    seven->next = eight;
    eight->prev = seven;

    eight->next = nine;
    nine->prev = eight;

    // 3 has child 7
    third->child = seven;

    cout << "Original list: ";
    printList(head);

    head = flatten(head);

    cout << "Flattened list: ";
    printList(head);

    return 0;
}