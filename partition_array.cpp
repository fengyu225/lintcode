/*
Given an array nums of integers and an int k, partition the array (i.e move the elements in "nums") such that:

All elements < k are moved to the left
All elements >= k are moved to the right
Return the partitioning index, i.e the first index i nums[i] >= k.

 Notice

You should do really partition in array nums instead of just counting the numbers of integers smaller than k.

If all elements in nums are smaller than k, then return nums.length

Example
If nums = [3,2,2,1] and k=2, a valid answer is 1.
*/

#include "header.h"

int partitionArray(vector<int> &nums, int k) {
    int sz = nums.size();
    int index = -1;
    int curr = 0;
    for(;curr<sz;curr++){
        if(nums[curr]>=k) continue;
        swap(nums[++index], nums[curr]);
    }
    return index+1;
}

int main(){
    vector<int> nums = {3, 2, 2, 1};
    cout<<partitionArray(nums, 20)<<endl;
    return 0;
}
