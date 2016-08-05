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

}

int main(){
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout<<removeDuplicates(nums)<<endl;
    return 0;
}
