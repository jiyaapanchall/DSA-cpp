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

Node* getIntersectionNode(Node* headA, Node* headB) {

    if (headA == nullptr || headB == nullptr) {
        return nullptr;
    }

    Node* p1 = headA;
    Node* p2 = headB;

    while (p1 != p2) {

        if (p1 == nullptr)
            p1 = headB;
        else
            p1 = p1->next;

        if (p2 == nullptr)
            p2 = headA;
        else
            p2 = p2->next;
    }

    return p1;
}

int main() {

    // Common part
    Node* common = new Node(7);
    common->next = new Node(8);

    // List A
    Node* headA = new Node(1);
    headA->next = new Node(2);
    headA->next->next = common;

    // List B
    Node* headB = new Node(4);
    headB->next = new Node(5);
    headB->next->next = new Node(6);
    headB->next->next->next = common;

    Node* intersection = getIntersectionNode(headA, headB);

    if (intersection != nullptr) {
        cout << "Intersection at node: "
             << intersection->data << endl;
    }
    else {
        cout << "No intersection" << endl;
    }

    return 0;
}