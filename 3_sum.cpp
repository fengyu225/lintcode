/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

 Notice

Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)

The solution set must not contain duplicate triplets.

Example
For example, given array S = {-1 0 1 2 -1 -4}, A solution set is:

(-1, 0, 1)
(-1, -1, 2)
*/

#include "header.h"

vector<vector<int> > threeSum(vector<int> &nums) {
    vector<vector<int> > res;
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    if(sz < 3) return res;
    vector<int> one_res(3, 0);
    for(int i=0; i+2<sz; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        int target = -1*nums[i];
        int j = i+1;
        int k = sz-1;
        while(j<k){
            int temp = nums[j]+nums[k];
            if(temp == target){
                one_res[0] = nums[i];
                one_res[1] = nums[j];
                one_res[2] = nums[k];
                res.push_back(one_res);
            }
            if(temp<=target){
                j++;
                while(j>i+1 && nums[j] == nums[j-1] && j<sz) j++;
            }
            else{
                k--;
                while(k<sz-1 && k>=0 && nums[k] == nums[k+1]) k--;
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {-4, -1, -1, 0, 1, 2};
    vector<vector<int> > res = threeSum(nums);
    for(auto v : res) print_vector<int>(v);
    return 0;
}
