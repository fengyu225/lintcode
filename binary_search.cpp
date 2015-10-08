/*
For a given sorted array (ascending order) and a target number, find the first index of this number in O(log n) time complexity.

If the target number does not exist in the array, return -1.


Example
If the array is [1, 2, 3, 3, 4, 5, 10], for given target 3, return 2.

Challenge
If the count of numbers is bigger than 2^32, can your code work properly?
*/

#include "header.h"

int binarySearch(vector<int> &array, int target) {
    long long sz = array.size();
    long long l = 0, r = sz-1;
    while(l+1<r){
        long long m = l+(r-l)/2;
        if(array[m]>target) r=m-1;
        else if(array[m]<target) l=m+1;
        else r=m;
    }
    return array[l] == target?l:array[r] == target?r:-1;
}

int main(){
    vector<int> array = {1, 2, 3, 3, 4, 5, 10};
    cout<<binarySearch(array, 3)<<endl;
    return 0;
}
