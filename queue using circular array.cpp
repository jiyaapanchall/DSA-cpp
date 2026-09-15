#include <iostream>
using namespace std;

class CircularQueue {
private:
    int arr[5];
    int frontIndex;
    int rearIndex;
    int count;
    const int capacity = 5;

public:
    CircularQueue() {
        frontIndex = 0;
        rearIndex = 0;
        count = 0;
    }

    // Check if queue is empty
    bool isEmpty() {
        return count == 0;
    }

    // Check if queue is full
    bool isFull() {
        return count == capacity;
    }

    // Add element
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue Overflow" << endl;
            return;
        }

        arr[rearIndex] = value;
        rearIndex = (rearIndex + 1) % capacity;
        count++;
    }

    // Remove element
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow" << endl;
            return;
        }

        frontIndex = (frontIndex + 1) % capacity;
        count--;
    }

    // Get front element
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        return arr[frontIndex];
    }

    // Display queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = 0; i < count; i++) {
            cout << arr[(frontIndex + i) % capacity] << " ";
        }

        cout << endl;
    }
};

int main() {
    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    cout << "Queue: ";
    q.display();

    q.dequeue();
    q.dequeue();

    cout << "After two dequeues: ";
    q.display();

    q.enqueue(60);
    q.enqueue(70);

    cout << "After adding 60 and 70: ";
    q.display();

    cout << "Front element: " << q.front() << endl;

    return 0;
}