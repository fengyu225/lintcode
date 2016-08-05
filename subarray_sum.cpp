/*

Given an integer array, find a subarray where the sum of numbers is zero. Your code should return the index of the first number and the index of the last number.

 Notice

There is at least one subarray that it's sum equals to zero.

Example
Given [-3, 1, 2, -3, 4], return [0, 2] or [1, 3].
*/

#include "header.h"

vector<int> subarraySum(vector<int> nums){
    int sz = nums.size();
    unordered_map<int,int> m;
    vector<int> arr(sz, 0);
    arr[0] = nums[0];
    vector<int> res(2, 0);
    if(arr[0] == 0) return res;
    m[arr[0]] = 0;
    for(int i=1; i<sz; i++){
        arr[i] = arr[i-1]+nums[i];
        if(m.find(arr[i]) != m.end()){
            res[0] = m[arr[i]]+1;
            res[1] = i;
            break;
        }
        else if(arr[i] == 0){
            res[1] = i;
            break;
        }
        m[arr[i]] = i;
    }
    return res;
}

int main(){
    vector<int> nums = {-3, 1, 2, -3, 4};
    vector<int> res = subarraySum(nums);
    print_vector<int>(res);
    return 0;
}
