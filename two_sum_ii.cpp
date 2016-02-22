/*
Given an array of integers, find how many pairs in the array such that their sum is bigger than a specific target number. Please return the number of pairs.

Example

Given numbers = [2, 7, 11, 15], target = 24. Return 1. (11 + 15 is the only pair)
Challenge

Do it in O(1) extra space and O(nlogn) time.
*/

#include "header.h"

int twoSum2(vector<int> &nums, int target) {
    // Write your code here
    int sz = nums.size();
    if(sz == 0 || sz == 1) return 0;
    sort(nums.begin(), nums.end());
    int l = 0, r = sz-1, res = 0;
    while(l<r){
        int temp = nums[l]+nums[r];
        if(temp<=target) l++;
        else{
            res+=(r-l);
            r--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    cout<<twoSum2(nums, 24)<<endl;
    return 0;
}