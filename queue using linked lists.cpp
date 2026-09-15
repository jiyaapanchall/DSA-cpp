#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) {
            data = value;
            next = nullptr;
        }
    };

    Node* frontNode;
    Node* rearNode;

public:
    Queue() {
        frontNode = nullptr;
        rearNode = nullptr;
    }

    // Destructor
    ~Queue() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }

        rearNode = nullptr;
    }

    // Check if queue is empty
    bool isEmpty() {
        return frontNode == nullptr;
    }

    // Add element
    void enqueue(int value) {
        Node* newNode = new Node(value);

        if (isEmpty()) {
            frontNode = rearNode = newNode;
        } else {
            rearNode->next = newNode;
            rearNode = newNode;
        }
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        Node* temp = frontNode;
        frontNode = frontNode->next;

        delete temp;

        // Queue became empty
        if (frontNode == nullptr) {
            rearNode = nullptr;
        }
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return frontNode->data;
    }

    // Display queue
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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Queue: ";
    q.display();

    cout << "Front element: " << q.front() << endl;

    q.dequeue();

    cout << "After dequeue: ";
    q.display();

    cout << "Front element: " << q.front() << endl;

    return 0;
}