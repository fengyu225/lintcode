/*
Given two strings, find the longest common substring.

Return the length of it.

 Notice

The characters in substring should occur continuously in original string. This is different with subsequence.

Example
Given A = "ABCD", B = "CBCE", return 2.
*/

#include "header.h"

int longestCommonSubstring(string &A, string &B) {
    int a_len = A.length();
    int b_len = B.length();
    vector<vector<int> > arr(a_len+1, vector<int>(b_len+1, 0));
    int res = 0;
    for(int i = 1; i<=a_len; i++){
        for(int j = 1; j<=b_len; j++){
            arr[i][j] = A[i-1] == B[j-1]?1+arr[i-1][j-1]:0; 
            res = max(res, arr[i][j]);
        }
    }
    return res;
}

int main(){
    string A = "abccccccccccde";
    string B = "dbccccccabccde";
    cout<<longestCommonSubstring(A, B)<<endl;
    return 0;
}
