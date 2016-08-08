/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.

Example
Given [4, 5, 6, 7, 0, 1, 2] return 0
*/

#include "header.h"

int findMin(vector<int> &num) {
    int sz = num.size(); 
    int l = 0, r = sz-1;
    if(sz == 1) return num[0];
    while(l+1<r){
        int m = l+(r-l)/2;
        if(num[l]<num[r] || num[m]<num[r]) r = m;
        else l = m;
    }
    return min(num[l], num[r]);
}

int main(){
    vector<int> num = {4, 5, 6, 7, 0, 1, 2};
    cout<<findMin(num)<<endl;
    return 0;
}
