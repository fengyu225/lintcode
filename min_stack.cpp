/*
Medium Min Stack

29% Accepted
Implement a stack with min() function, which will return the smallest number in the stack.

It should support push, pop and min operation all in O(1) cost.


Example
Operations: push(1), pop(), push(2), push(3), min(), push(1), min() Return: 1, 2, 1

Note
min operation will never be called if there is no number in the stack
*/

#include "header.h"

class MinStack {
public:
    MinStack() {
        // do initialization if necessary
    }

    void push(int number) {
        // write your code here
    }

    int pop() {
        // write your code here
    }

    int min() {
        // write your code here
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
