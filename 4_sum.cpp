/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?

Find all unique quadruplets in the array which gives the sum of target.

 Notice

Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
The solution set must not contain duplicate quadruplets.

Example
Given array S = {1 0 -1 0 -2 2}, and target = 0. A solution set is:

(-1, 0, 0, 1)
(-2, -1, 1, 2)
(-2, 0, 0, 2)
*/

#include "header.h"

vector<vector<int> > fourSum(vector<int> nums, int target) {
    vector<vector<int> > res;
    int sz = nums.size();
    sort(nums.begin(), nums.end());
    for(int i=0; i+3<sz; i++){
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j+2<sz; j++){
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int temp_target = target-nums[i]-nums[j];
            int a = j+1, b = sz-1;
            while(a<b){
                int temp = nums[a]+nums[b];
                if(temp == temp_target){
                    vector<int> temp_v;
                    temp_v.push_back(nums[i]);
                    temp_v.push_back(nums[j]);
                    temp_v.push_back(nums[a]);
                    temp_v.push_back(nums[b]);
                    res.push_back(temp_v);
                }
                if(temp<=temp_target){
                    a++;
                    while(a>j+1 && a<sz && nums[a] == nums[a-1]) a++;
                }
                else{
                    b--;
                    while(b+1<sz && b>=0 && nums[b] == nums[b+1]) b--;
                }
            }
        }
    }
    return res;
}

int main(){
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    vector<vector<int> > res = fourSum(nums, 0);
    for(auto v : res) print_vector<int>(v);
    return 0;
}
