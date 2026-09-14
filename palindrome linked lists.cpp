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

// Reverse a linked list
Node* reverseList(Node* head) {

    Node* prev = nullptr;
    Node* current = head;

    while (current != nullptr) {

        Node* nextNode = current->next;

        current->next = prev;

        prev = current;
        current = nextNode;
    }

    return prev;
}

bool isPalindrome(Node* head) {

    if (head == nullptr || head->next == nullptr) {
        return true;
    }

    // Step 1: Find middle
    Node* slow = head;
    Node* fast = head;

    while (fast->next != nullptr &&
           fast->next->next != nullptr) {

        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* secondHalf = reverseList(slow->next);

    // Step 3: Compare both halves
    Node* firstHalf = head;
    Node* temp = secondHalf;

    while (temp != nullptr) {

        if (firstHalf->data != temp->data) {
            return false;
        }

        firstHalf = firstHalf->next;
        temp = temp->next;
    }

    return true;
}

int main() {

    Node* head = new Node(1);

    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(1);

    if (isPalindrome(head)) {
        cout << "Palindrome" << endl;
    }
    else {
        cout << "Not a palindrome" << endl;
    }

    return 0;
}