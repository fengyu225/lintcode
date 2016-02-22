/*
Find K-th largest element in an array.


Example
In array [9,3,2,4,8], the 3rd largest element is 4.

In array [1,2,3,4,5], the 1st largest element is 5, 2nd largest element is 4, 3rd largest element is 3 and etc.

Note
You can swap elements in the array

Challenge
O(n) time, O(1) extra memory.
*/

#include "header.h"

int kthLargestElement(int k, vector<int> nums) {
    int sz = nums.size();
    int l = 0, r = sz-1;
    while(l<r){
        int curr = l+1, tail = l;
        for(;curr<=r;curr++)
            if(nums[curr]>=nums[l]) swap(nums[++tail], nums[curr]);
        swap(nums[tail], nums[l]);
        if(tail-l+1 == k) return nums[tail];
        else if(tail-l+1 < k){
            k -= (tail-l+1);
            l = tail+1;
        }
        else r = tail;
    }
    return nums[l];
}

int main(){
    vector<int> nums = {9, 3, 2, 4, 8};
    cout<<kthLargestElement(3, nums)<<endl;
    return 0;
}
