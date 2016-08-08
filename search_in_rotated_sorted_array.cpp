/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Example
For [4, 5, 1, 2, 3] and target=1, return 2.

For [4, 5, 1, 2, 3] and target=0, return -1.
*/

#include "header.h"

int search(vector<int> &A, int target) {
    int sz = A.size();
    int l = 0, r = sz-1;
    if(sz == 0) return -1;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(target == A[m]) return m;
        if(A[m]>A[0]){
            if(target<A[m] && target>=A[0]) r = m-1;
            else l = m+1;
        }
        else{//A[m]<A[0]
            if(target>A[m] && target<=A[sz-1]) l = m+1;
            else r = m-1;
        }
    }
    return A[l] == target?l:(A[r] == target?r:-1);
}

int main(){
    //vector<int> A = {4, 5, 1, 2, 3};
    vector<int> A = {3, 1};
    cout<<search(A, 1)<<endl;
    return 0;
}
