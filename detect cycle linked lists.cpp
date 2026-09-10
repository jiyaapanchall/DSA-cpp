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

bool hasCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        // They meet
        if (slow == fast) {
            return true;
        }
    }

    return false;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    // Create cycle:
    // 4 → 3
    head->next->next->next->next =
        head->next->next;

    if (hasCycle(head)) {
        cout << "Cycle exists" << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}