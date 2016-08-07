/*
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.

Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.
*/

#include "header.h"

int binarySearch(vector<int> &array, int target) {
    int sz = array.size();
    int l = 0, r = sz-1;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(array[m] == target) r = m;
        else if(array[m] < target) l = m+1;
        else r = m-1;
    }
    return array[l] == target?l:array[r] == target?r:-1;
}

int main(){
    vector<int> array = {1, 2, 3, 3, 4, 5, 10};
    cout<<binarySearch(array, 3)<<endl;
    return 0;
}
