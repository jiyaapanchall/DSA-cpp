#include <iostream>
using namespace std;

class Deque {
private:
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

    Node* frontNode;
    Node* rearNode;

public:
    Deque() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    ~Deque() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }

        rearNode = nullptr;
    }

    bool empty() {
        return frontNode == nullptr;
    }

    // Insert at front
    void push_front(int value) {
        Node* newNode = new Node(value);

        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }
    }

    // Insert at rear
    void push_back(int value) {
        Node* newNode = new Node(value);

        if (empty()) {
            frontNode = rearNode = newNode;
        } else {
            newNode->prev = rearNode;
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Delete from front
    void pop_front() {
        if (empty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = frontNode;

        if (frontNode == rearNode) {
            frontNode = rearNode = nullptr;
        } else {
            frontNode = frontNode->next;
            frontNode->prev = nullptr;
        }

        delete temp;
    }

    // Delete from rear
    void pop_back() {
        if (empty()) {
            cout << "Deque is empty" << endl;
            return;
        }

        Node* temp = rearNode;

        if (frontNode == rearNode) {
            frontNode = rearNode = nullptr;
        } else {
            rearNode = rearNode->prev;
            rearNode->next = nullptr;
        }

        delete temp;
    }

    int front() {
        if (empty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        return frontNode->data;
    }

    int back() {
        if (empty()) {
            cout << "Deque is empty" << endl;
            return -1;
        }

        return rearNode->data;
    }

    void display() {
        Node* current = frontNode;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    Deque dq;

    dq.push_back(20);
    dq.push_back(30);

    dq.push_front(10);
    dq.push_front(5);

    cout << "Deque: ";
    dq.display();

    cout << "Front: " << dq.front() << endl;
    cout << "Rear: " << dq.back() << endl;

    dq.pop_front();

    cout << "After pop_front: ";
    dq.display();

    dq.pop_back();

    cout << "After pop_back: ";
    dq.display();

    return 0;
}