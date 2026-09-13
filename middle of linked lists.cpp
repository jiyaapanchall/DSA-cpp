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

Node* findMiddle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printList(Node* head) {

    while (head != nullptr) {
        cout << head->data << " → ";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Linked List: ";
    printList(head);

    Node* middle = findMiddle(head);

    cout << "Middle element: "
         << middle->data << endl;

    return 0;
}