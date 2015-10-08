/*
Given a list of numbers, return all possible permutations.


Example
For nums = [1,2,3], the permutations are:

[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
Challenge
Do it without recursion.
*/

#include "header.h"

vector<vector<int> > permute(vector<int> nums) {
    vector<vector<int> > res;
}

int main(){
    vector<int> nums = {1, 2, 3};
    print_2d_vector<int>(permute(nums));
    return 0;
}
