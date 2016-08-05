/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are NOT zero-based.

 Notice

You may assume that each input would have exactly one solution

Have you met this question in a real interview? Yes
Example
numbers=[2, 7, 11, 15], target=9

return [1, 2]
*/

#include "header.h"

vector<int> twoSum(vector<int> &nums, int target) {
    int sz = nums.size();
    vector<int> res;
    unordered_map<int,int> m;
    for(int i=0; i<sz; i++){
        if(m.find(target-nums[i]) != m.end()){
            res.push_back(m[target-nums[i]]+1);
            res.push_back(i+1);
            return res;
        }
        m[nums[i]] = i;
    }
}

int main(){
    vector<int> nums = {2, 7, 11, 15};
    vector<int> res = twoSum(nums, 9);
    print_vector<int>(res);
    return 0;
}
