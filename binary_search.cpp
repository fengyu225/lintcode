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

}

int main(){
    vector<int> array = {1, 2, 3, 3, 4, 5, 10};
    cout<<binarySearch(array, 3)<<endl;
    return 0;
}
