#include <iostream>
#include <stack>
#include <climits>
using namespace std;

stack<int> st;
stack<int> min_stack;

int min() {
    if(min_stack.empty()) {
        return INT_MAX;
    }
    
    return min_stack.top();
}

void push(int data) {
    st.push(data);
    if(data < min()) {
        min_stack.push(data);
    }
    cout << "Push " << data << "\tmin " << min() << endl;
}

void pop() {
    int data = st.top();
    if(data == min()) {
        min_stack.pop();
    }
    st.pop();
    cout << "Pop " << data << "\tmin " << min() << endl;
}

int main() {
    // let's push and pop from stack and monitor min();
    push(5);
    push(6);
    push(3);
    push(4);
    push(2);
    push(7);
    push(1);
    push(8);
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    
    return 0;
}
