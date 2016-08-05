/*

Given two sorted integer arrays A and B, merge B into A as one sorted array.

 Notice

You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.

Example
A = [1, 2, 3, empty, empty], B = [4, 5]

After merge, A will be filled as [1, 2, 3, 4, 5]
*/

#include "header.h"

void mergeSortedArray(int A[], int m, int B[], int n) {
    int curr = m+n-1;
    int curr_a = m-1;
    int curr_b = n-1;
    while(curr_a>=0 || curr_b >=0){
        if(curr_a<0 || (curr_b>=0 && B[curr_b]>A[curr_a]))
            A[curr--] = B[curr_b--];
        else A[curr--] = A[curr_a--];
    }
}

int main(){
    int A[] = {1, 2, 3, 0, 0};
    int B[] = {4, 5};
    mergeSortedArray(A, 3, B, 2);
    for(int i=0; i<5; i++) cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
