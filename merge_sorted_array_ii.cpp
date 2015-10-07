/*
Merge two given sorted integer array A and B into a new sorted integer array.


Example
A=[1,2,3,4]

B=[2,4,5,6]

return [1,2,2,3,4,4,5,6]

Challenge
How can you optimize your algorithm if one array is very large and the other is very small?
*/

#include "header.h"

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
    int a_sz = A.size(), b_sz = B.size();
    vector<int> res(a_sz+b_sz, 0);
    int a_curr = 0, b_curr = 0, tail = -1;
    while(a_curr<a_sz || b_curr<b_sz){
        if(b_curr == b_sz || a_curr<a_sz && A[a_curr]<B[b_curr]) res[++tail] = A[a_curr++];
        else res[++tail] = B[b_curr++];
    }
    return res;
}

vector<int> mergeSortedArray(vector<int> &A, vector<int> &B) {
int main(){
    vector<int> A = {1, 2, 3, 4};
    vector<int> B = {2, 4, 5, 6};
    print_vector<int>(mergeSortedArray(A,B));
    return 0;
}
