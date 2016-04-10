#include <iostream>
#include <stack>
using namespace std;

void sort_descending(stack<int>& st) {
    // create a buffer stack
    stack<int> buffer;

    while(!st.empty()) {
        // pick the top element of st
        int top = st.top();
        st.pop();
        int count = 0;
        // move all the smaller element of buffer to stack
        while(!buffer.empty() && top > buffer.top()) {
            int t = buffer.top();
            buffer.pop();
            st.push(t);
            ++count;
        }
        buffer.push(top);

        // move back from st to buffer
        while(count > 0) {
            int t = st.top();
            st.pop();
            buffer.push(t);
            --count;
        }
    }

    // buffer is now sorted in ascending order
    // reverse it in st
    while(!buffer.empty()) {
        int top = buffer.top();
        buffer.pop();
        st.push(top);
    }
}

void print_stack(stack<int> st) {
    while(!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
}

int main() {
    stack<int> st;

    // add elements to stack
    st.push(4);
    st.push(10);
    st.push(3);
    st.push(2);
    st.push(9);
    st.push(1);
    st.push(5);

    // sort the stack
    sort_descending(st);

    // print content of stack
    print_stack(st);
    return 0;
}
