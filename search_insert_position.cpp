/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume NO duplicates in the array.

Have you met this question in a real interview? Yes
Example
[1,3,5,6], 5 → 2

[1,3,5,6], 2 → 1

[1,3,5,6], 7 → 4

[1,3,5,6], 0 → 0
*/

#include "header.h"

int searchInsert(vector<int> &A, int target) {
    int sz = A.size();
    int l = 0, r = sz-1;
    if(sz == 0) return 0;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(A[m] == target) return m;
        else if(A[m]<target) l = m+1;
        else r = m;
    }
    if(r == sz-1 && A[r]<target) return sz;
    return A[l]>=target?l:r; 
}

int main(){
    vector<int> A = {1, 3, 5, 6};
    cout<<searchInsert(A, 5)<<endl;
    cout<<searchInsert(A, 2)<<endl;
    cout<<searchInsert(A, 7)<<endl;
    cout<<searchInsert(A, 0)<<endl;
    return 0;
}
