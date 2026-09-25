#include <iostream>
#include <stack>
using namespace std;

class MinStack {

private:
    stack<int> st;
    stack<int> minSt;

public:

    void push(int val) {

        st.push(val);

        if (minSt.empty() || val <= minSt.top()) {
            minSt.push(val);
        }
    }

    void pop() {

        if (st.top() == minSt.top()) {
            minSt.pop();
        }

        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return minSt.top();
    }
};

int main() {

    MinStack st;

    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Minimum: " << st.getMin() << endl;

    st.pop();

    cout << "Minimum after pop: "
         << st.getMin() << endl;

    return 0;
}