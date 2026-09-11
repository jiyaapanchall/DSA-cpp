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

Node* addTwoNumbers(Node* l1, Node* l2) {

    Node* dummy = new Node(0);
    Node* current = dummy;

    int carry = 0;

    while (l1 != nullptr ||
           l2 != nullptr ||
           carry != 0) {

        int sum = carry;

        if (l1 != nullptr) {
            sum += l1->data;
            l1 = l1->next;
        }

        if (l2 != nullptr) {
            sum += l2->data;
            l2 = l2->next;
        }

        int digit = sum % 10;
        carry = sum / 10;

        current->next = new Node(digit);
        current = current->next;
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

    // 342
    Node* l1 = new Node(2);
    l1->next = new Node(4);
    l1->next->next = new Node(3);

    // 465
    Node* l2 = new Node(5);
    l2->next = new Node(6);
    l2->next->next = new Node(4);

    Node* result = addTwoNumbers(l1, l2);

    cout << "Result: ";
    printList(result);

    return 0;
}