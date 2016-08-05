/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

Example
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
*/

#include "header.h"

int removeDuplicates(vector<int> &nums) {
    int sz = nums.size();
    int last_index = 0;
    if(sz == 0) return last_index;
    for(int i=1; i<sz; i++){
        if(nums[i] == nums[last_index]) continue;
        nums[++last_index] = nums[i];
    }
    return last_index+1;
}

int main(){
    vector<int> nums = {1, 1, 2};
    cout<<removeDuplicates(nums)<<endl;
    return 0;
}
