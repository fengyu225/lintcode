/*
Ugly number is a number that only have factors 3, 5 and 7.

Design an algorithm to find the Kth ugly number. The first 5 ugly numbers are 3, 5, 7, 9, 15 ...


Example
If K=4, return 9.

Challenge
O(K log K) or O(K) time.
*/

#include "header.h"

long long kthPrimeNumber(int k) {
    if(k == 1) return 3;
    deque<long long> q;
    q.push_back(1);
    int curr = 1;
    long long three = 0, five = 0, seven = 0;
    while(curr<=k){
        long temp = min(q[three]*3, min(q[five]*5, q[seven]*7));
        q.push_back(temp);
        if(temp%3 == 0) three++;
        if(temp%5 == 0) five++;
        if(temp%7 == 0){
            q.pop_front();
            three--;
            five--;
        }
        curr++;
    }
    return q.back();
}

int main(){
    cout<<kthPrimeNumber(4)<<endl;
    return 0;
}
