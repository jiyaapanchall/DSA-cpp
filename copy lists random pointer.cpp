#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {

    int val;
    Node* next;
    Node* random;

    Node(int value) {
        val = value;
        next = nullptr;
        random = nullptr;
    }
};

Node* copyRandomList(Node* head) {

    if (head == nullptr) {
        return nullptr;
    }

    unordered_map<Node*, Node*> mp;

    Node* current = head;

    // Step 1: Create copies
    while (current != nullptr) {

        mp[current] = new Node(current->val);

        current = current->next;
    }

    // Step 2: Connect next and random pointers
    current = head;

    while (current != nullptr) {

        mp[current]->next = mp[current->next];

        mp[current]->random = mp[current->random];

        current = current->next;
    }

    return mp[head];
}

void printList(Node* head) {

    Node* current = head;

    while (current != nullptr) {

        cout << "Node: " << current->val;

        if (current->random != nullptr) {
            cout << ", Random: "
                 << current->random->val;
        }
        else {
            cout << ", Random: NULL";
        }

        cout << endl;

        current = current->next;
    }
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    // Random pointers
    head->random = head->next->next;          // 1 → 3
    head->next->random = head;                // 2 → 1
    head->next->next->random = head->next;    // 3 → 2

    cout << "Original List:\n";
    printList(head);

    Node* copiedHead = copyRandomList(head);

    cout << "\nCopied List:\n";
    printList(copiedHead);

    return 0;
}