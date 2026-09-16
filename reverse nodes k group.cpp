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

Node* reverseKGroup(Node* head, int k) {

    if (head == nullptr || k == 1) {
        return head;
    }

    Node* dummy = new Node(0);
    dummy->next = head;

    Node* groupPrev = dummy;

    while (true) {

        // Find the kth node
        Node* kth = groupPrev;

        for (int i = 0; i < k; i++) {

            kth = kth->next;

            if (kth == nullptr) {

                Node* result = dummy->next;
                delete dummy;

                return result;
            }
        }

        Node* groupNext = kth->next;

        // Reverse the group
        Node* prev = groupNext;
        Node* current = groupPrev->next;

        while (current != groupNext) {

            Node* nextNode = current->next;

            current->next = prev;

            prev = current;
            current = nextNode;
        }

        // Connect previous group
        Node* oldGroupStart = groupPrev->next;

        groupPrev->next = kth;

        // Move to next group
        groupPrev = oldGroupStart;
    }
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

    int k = 2;

    cout << "Original list: ";
    printList(head);

    head = reverseKGroup(head, k);

    cout << "After reversing in groups: ";
    printList(head);

    return 0;
}