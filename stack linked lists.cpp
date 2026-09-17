#include <iostream>
using namespace std;

class Stack {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value, Node* nextNode = nullptr) {
            data = value;
            next = nextNode;
        }
    };

    Node* topNode;

public:
    Stack() {
        topNode = nullptr;
    }

    // Destructor to free memory
    ~Stack() {
        while (topNode != nullptr) {
            Node* temp = topNode;
            topNode = topNode->next;
            delete temp;
        }
    }

    // Check if stack is empty
    bool empty() const {
        return topNode == nullptr;
    }

    // Push element
    void push(int value) {
        topNode = new Node(value, topNode);
    }

    // Pop element
    void pop() {
        if (empty()) {
            cout << "Stack Underflow" << endl;
            return;
        }

        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }

    // Return top element
    int top() const {
        if (empty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }

        return topNode->data;
    }

    // Display stack
    void display() const {
        Node* current = topNode;

        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack: ";
    st.display();

    cout << "Top element: " << st.top() << endl;

    st.pop();

    cout << "After pop: ";
    st.display();

    cout << "Top element: " << st.top() << endl;

    return 0;
}