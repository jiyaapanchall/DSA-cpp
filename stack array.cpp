#include <iostream>
using namespace std;

class Stack {

private:

    int arr[100];
    int topIndex;

public:

    Stack() {
        topIndex = -1;
    }

    // Push element
    void push(int value) {

        if (topIndex == 99) {
            cout << "Stack Overflow\n";
            return;
        }

        topIndex++;
        arr[topIndex] = value;
    }

    // Pop element
    void pop() {

        if (topIndex == -1) {
            cout << "Stack Underflow\n";
            return;
        }

        topIndex--;
    }

    // Return top element
    int top() {

        if (topIndex == -1) {
            cout << "Stack is empty\n";
            return -1;
        }

        return arr[topIndex];
    }

    // Check empty
    bool empty() {

        return topIndex == -1;
    }

    // Display stack
    void display() {

        if (empty()) {
            cout << "Stack is empty\n";
            return;
        }

        for (int i = topIndex; i >= 0; i--) {
            cout << arr[i] << " ";
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

    cout << "Top element: "
         << st.top() << endl;

    st.pop();

    cout << "After pop: ";
    st.display();

    cout << "Top element: "
         << st.top() << endl;

    return 0;
}