/*
Given an integers array A.

Define B[i] = A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1], calculate B WITHOUT divide operation.

Example
For A = [1, 2, 3], return [6, 3, 2].
*/

#include "header.h"

vector<long long> productExcludeItself(vector<int> &nums) {
    int sz = nums.size();
    vector<long long> res(sz, 0);
    return res;
}

int main(){
    vector<int> nums = {1, 2, 3, 4};
    vector<long long> res = productExcludeItself(nums);
    print_vector<long long>(res);
    return 0;
}
