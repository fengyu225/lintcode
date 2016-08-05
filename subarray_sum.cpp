/*

Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

 Notice

There is at least one subarray that it's sum equals to zero.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
*/

#include "header.h"

vector<int> subarraySum(vector<int> nums){

}

int main(){
    vector<int> nums = {-3, 1, 2, -3, 4};
    vector<int> res = subarraySum(nums);
    print_vector<int>(res);
    return 0;
}
