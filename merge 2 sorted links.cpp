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

Node* mergeLists(Node* list1, Node* list2) {

    Node dummy(0);
    Node* current = &dummy;

    while (list1 != nullptr &&
           list2 != nullptr) {

        if (list1->data <= list2->data) {

            current->next = list1;
            list1 = list1->next;
        }
        else {

            current->next = list2;
            list2 = list2->next;
        }

        current = current->next;
    }

    // Attach remaining nodes
    if (list1 != nullptr) {
        current->next = list1;
    }
    else {
        current->next = list2;
    }

    return dummy.next;
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

    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    Node* result = mergeLists(list1, list2);

    cout << "Merged list: ";
    printList(result);

    return 0;
}