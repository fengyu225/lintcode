/*
Given an unsorted integer array, find the first missing positive integer.

Example
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.
*/

#include "header.h"

int firstMissingPositive(vector<int> A) {
    int sz = A.size();
    if(sz == 0) return 1;
    for(int i=0; i<sz; i++){
        while(A[i]>=0 && A[i]<sz && A[i] != i && A[i] != A[A[i]])
            swap(A[i], A[A[i]]);
    }
    for(int i=1; i<sz; i++) if(A[i] != i) return i;
    return A[0] == sz?sz+1:sz;
}

int main(){
    //vector<int> arr = {2, 2, 2, 2};
    vector<int> arr = {1, 1000};
    cout<<firstMissingPositive(arr)<<endl;
    return 0;
}
