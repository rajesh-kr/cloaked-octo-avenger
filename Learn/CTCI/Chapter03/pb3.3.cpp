#include <iostream>
#include <vector>
#include <stack>
using namespace std;

template <class T>
class SetOfStacks {
    private:
        vector<stack<T> > stacks;
        int max_size;
        int current_stack;

    public:
        SetOfStacks(int m) :max_size(m), current_stack(0) {
            stacks.push_back(stack<T>());
        }

        ~SetOfStacks() {
            stacks.clear();
        }

        void push(T data) {
            stacks[current_stack].push(data);
            if(stacks[current_stack].size() >= max_size) {
                stacks.push_back(stack<T>());
                current_stack++;
            }
        }

        T pop() {
            T data = stacks[current_stack].top();
            stacks[current_stack].pop();
            if(stacks[current_stack].size() == 0) {
                stacks.pop_back();
                current_stack--;
            }

            return data;
        }

        T popAt(int index) {
            T data;
            if(index <= current_stack) {
                data = stacks[index].top();
                stacks[index].pop();
            }

            return data;
        }
};

int main() {
    SetOfStacks<int> sos(3);
    sos.push(5);
    sos.push(2);
    sos.push(1);
    sos.push(6);
    int d = sos.pop();
    int k = sos.popAt(0);
    int c = sos.pop();
    cout << d << endl;
    cout << k << endl;
    cout << c << endl;
    return 0;
}
