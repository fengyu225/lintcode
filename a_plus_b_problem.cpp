/*
Write a function that add two numbers A and B. You should not use + or any arithmetic operators.

Have you met this question in a real interview? Yes
Example
Given a=1 and b=2 return 3

Note
There is no need to read data from standard input stream. Both parameters are given in function aplusb, you job is to calculate the sum and return it.

Challenge
Of course you can just return a + b to get accepted. But Can you challenge not do it like that?

Clarification
Are a and b both 32-bit integers?

Yes.
Can I use bit operation?

Sure you can.
*/

#include "header.h"

int aplusb(int a, int b) {
    while(b){
        int carry = a&b;
        a = a^b;
        b = carry<<1;
    }
    return a;
}

int main(){
    cout<<aplusb(1, 2)<<endl;
    cout<<aplusb(1, -1)<<endl;
    return 0;
}