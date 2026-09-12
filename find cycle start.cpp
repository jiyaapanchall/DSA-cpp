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

Node* detectCycle(Node* head) {

    Node* slow = head;
    Node* fast = head;

    // Step 1: Detect cycle
    while (fast != nullptr &&
           fast->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {

            // Step 2:
            // Move one pointer to head
            Node* entry = head;

            // Move both one step at a time
            while (entry != slow) {
                entry = entry->next;
                slow = slow->next;
            }

            // Cycle starting point
            return entry;
        }
    }

    // No cycle
    return nullptr;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Create cycle:
    // 5 → 3
    head->next->next->next->next =
        head->next->next;

    Node* cycleStart = detectCycle(head);

    if (cycleStart != nullptr) {
        cout << "Cycle starts at node: "
             << cycleStart->data << endl;
    }
    else {
        cout << "No cycle" << endl;
    }

    return 0;
}