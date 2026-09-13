#include <iostream>
using namespace std;

struct Node {

    int data;
    Node* prev;
    Node* next;

    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList {

private:

    Node* head;

public:

    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int value) {

        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
        newNode->prev = current;
    }

    // Insert at a specific position
    void insertAtPosition(int value, int position) {

        if (position <= 1) {
            insertAtBeginning(value);
            return;
        }

        Node* current = head;

        for (int i = 1;
             i < position - 1 && current != nullptr;
             i++) {

            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        Node* newNode = new Node(value);

        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != nullptr) {
            current->next->prev = newNode;
        }

        current->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;

        head = head->next;

        if (head != nullptr) {
            head->prev = nullptr;
        }

        delete temp;
    }

    // Delete from end
    void deleteFromEnd() {

        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        if (current->prev != nullptr) {
            current->prev->next = nullptr;
        }
        else {
            // Only one node
            head = nullptr;
        }

        delete current;
    }

    // Delete from a specific position
    void deleteFromPosition(int position) {

        if (head == nullptr || position <= 0) {
            cout << "Invalid position\n";
            return;
        }

        Node* current = head;

        for (int i = 1;
             i < position && current != nullptr;
             i++) {

            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position\n";
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        }
        else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        }

        delete current;
    }

    // Forward traversal
    void displayForward() {

        Node* current = head;

        while (current != nullptr) {

            cout << current->data;

            if (current->next != nullptr) {
                cout << " ⇄ ";
            }

            current = current->next;
        }

        cout << endl;
    }

    // Backward traversal
    void displayBackward() {

        if (head == nullptr) {
            return;
        }

        Node* current = head;

        while (current->next != nullptr) {
            current = current->next;
        }

        while (current != nullptr) {

            cout << current->data;

            if (current->prev != nullptr) {
                cout << " ⇄ ";
            }

            current = current->prev;
        }

        cout << endl;
    }
};

int main() {

    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "Original list: ";
    list.displayForward();

    list.insertAtBeginning(5);

    cout << "After inserting 5 at beginning: ";
    list.displayForward();

    list.insertAtPosition(15, 3);

    cout << "After inserting 15 at position 3: ";
    list.displayForward();

    list.deleteFromBeginning();

    cout << "After deleting from beginning: ";
    list.displayForward();

    list.deleteFromEnd();

    cout << "After deleting from end: ";
    list.displayForward();

    list.deleteFromPosition(2);

    cout << "After deleting position 2: ";
    list.displayForward();

    cout << "Backward traversal: ";
    list.displayBackward();

    return 0;
}