/*
There is an integer array which has the following features:

The numbers in adjacent positions are different.
A[0] < A[1] && A[A.length - 2] > A[A.length - 1].
We define a position P is a peek if:

A[P] > A[P-1] && A[P] > A[P+1]
Find a peak element in this array. Return the index of the peak.

 Notice

The array may contains multiple peeks, find any of them.

Example
Given [1, 2, 1, 3, 4, 5, 7, 6]

Return index 1 (which is number 2) or 6 (which is number 7)
*/

#include "header.h"

int findPeak(vector<int> A) {
    int sz = A.size();
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(A[m]>A[m-1] && A[m]>A[m+1]) return m;
        if(A[m+1]>A[m]) l = m+1;
        else r = m-1;
    }
    return A[l]>A[r]?l:r;
}

int main(){
    vector<int> A = {1, 2, 1, 3, 4, 5, 7, 6};
    cout<<findPeak(A)<<endl;
    return 0;
}
