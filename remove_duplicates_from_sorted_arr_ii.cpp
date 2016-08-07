/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/

#include "header.h"

int removeDuplicates(vector<int> &nums) {
    int sz = nums.size();
    int index = -1;
    int count = 1;
    for(int curr=0; curr<sz; curr++){
        if(index == -1 || nums[index] != nums[curr]){
            nums[++index] = nums[curr];
            count = 1;
        }
        else if(count<2){
            nums[++index] = nums[curr];
            count++;
        }
    }
    return index+1;
}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout<<removeDuplicates(nums)<<endl;
    print_vector<int>(nums);
    return 0;
}
