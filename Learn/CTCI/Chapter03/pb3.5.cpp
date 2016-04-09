#include <iostream>
#include <stack>
using namespace std;

template <class T>
class MyQueue {
    private:
        stack<T> stack1; // always push new element to top of stack1
        stack<T> stack2; // and always remove from top of stack2

    public:
        void add(T data) {
            // whenever we want to add element to queue,
            // we move everything from stack2 to stack1 first
            // and then add new element to stack1
            while(!stack2.empty()) {
                T t = stack2.top();
                stack2.pop();
                stack1.push(t);
            }
            stack1.push(data);
        }

        T remove() {
            // whenever we want to remove element from queue,
            // we move everything from stack1 to stack2 first
            // and then remove the top element from stack2
            while(!stack1.empty()) {
                T t = stack1.top();
                stack1.pop();
                stack2.push(t);
            }

            T t = stack2.top();
            stack2.pop();
            return t;
        }

        int size() {
            return stack1.size() + stack2.size();
        }
};

int main() {
    MyQueue<int> q;
    q.add(5);
    q.add(6);
    int t = q.remove();
    cout << t << endl;
    return 0;
}
