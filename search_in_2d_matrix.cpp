/*
Write an efficient algorithm that searches for a value in an m x n matrix.

This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.

Example
Consider the following matrix:

[
    [1, 3, 5, 7],
    [10, 11, 16, 20],
    [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include "header.h"

bool searchMatrix(vector<vector<int> > &matrix, int target) {
    int m = matrix.size();
    if(m == 0) return false;
    int n = matrix[0].size();
    if(n == 0) return false;
    int l = 0, r = m-1;
    while(l+1<r){
        int mid = l+(r-l)/2;
        if(matrix[mid][0] == target) return true;
        if(matrix[mid][0] < target) l = mid;
        else r = mid-1;
    }
    if(matrix[l][0] == target || matrix[r][0] == target) return true;
    int row = matrix[r][0]<target?r:l;
    l = 0, r = n-1;
    while(l<r){
        int mid = l+(r-l)/2;
        if(matrix[row][mid] == target) return true;
        if(matrix[row][mid] < target) l = mid+1;
        else r=mid-1;
    }
    return matrix[row][l] == target;
}

int main(){
    vector<vector<int> > matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };
    cout<<searchMatrix(matrix, 7)<<endl;
    return 0;
}
