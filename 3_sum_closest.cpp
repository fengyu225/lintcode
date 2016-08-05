/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers.

 Notice

You may assume that each input would have exactly one solution.

Example
For example, given array S = [-1 2 1 -4], and target = 1. The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include "header.h"

int threeSumClosest(vector<int> nums, int target) {
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    int res = INT_MAX;
    for(int i=0; i+2<sz; i++){
        int temp_t = target-nums[i];
        int j = i+1;
        int k = sz-1;
        while(j<k){
            int t = nums[j]+nums[k];
            if(abs(t+nums[i]-target)<abs(res-target)) res = t+nums[i];
            if(t<temp_t) j++;
            else k--;
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-1, 2, 1, -4};
    cout<<threeSumClosest(nums, 1)<<endl;
    return 0;
}
