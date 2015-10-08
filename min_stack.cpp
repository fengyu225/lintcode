/*
Medium Min Stack

Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.


Example
Operations: push(1), pop(), push(2), push(3), min(), push(1), min() Return: 1, 2, 1

Note
min operation will never be called if there is no number in the stack
*/

#include "header.h"

class MinStack {
    stack<int> s;
    stack<int> m;
public:
    MinStack() {}

    void push(int number) {
        s.push(number);
        if(m.empty() || m.top()>=number) m.push(number);
    }

    int pop() {
        int n = s.top();
        s.pop();
        if(!m.empty() && m.top() == n) m.pop();
        return n;
    }

    int min() {
        return m.top();
    }
};

int main(){
    MinStack s;
    s.push(3);
    s.push(2);
    s.push(3);
    cout<<s.min()<<endl;
    s.pop();
    cout<<s.min()<<endl;
    s.pop();
    cout<<s.min()<<endl;
    return 0;
}
