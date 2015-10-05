/*
Write an algorithm which computes the number of trailing zeros in n factorial.

Have you met this question in a real interview? Yes
Example
11! = 39916800, so the out should be 2

Challenge
O(log N) time
*/

#include "header.h"

long long trailingZeros(long long n) {
    long long res = 0;
    while(n>=5){
        res += n/5;
        n = n/5;
    }
    return res;
}

int main(){
    cout<<trailingZeros(11)<<endl;
    cout<<trailingZeros(26)<<endl;
    cout<<trailingZeros(30)<<endl;
    cout<<trailingZeros(5555550000000)<<endl;
    return 0;
}