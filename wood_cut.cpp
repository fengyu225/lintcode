/*
Given n pieces of wood with length L[i] (integer array). Cut them into small pieces to guarantee you could have equal or more than k pieces with the same length. What is the longest length you can get from the n pieces of wood? Given L & k, return the maximum length of the small pieces.

 Notice

You couldn't cut wood into float length.

Example
For L=[232, 124, 456], k=7, return 114.
*/

#include "header.h"

int woodCut(vector<int> L, int k) {
    int res = 0;
    if(L.size() == 0) return 0;
    int l = 0, r = *max_element(L.begin(), L.end());
    while(l<r){
        int m = l+(r-l);
        int temp = 0;
        for(int i : L) temp += i/m;
        if(temp<k) r = m-1;
        else{
            res = max(res, m);
            l = m+1;
        }
    }
    return res;
}

int main(){
    vector<int> L = {232, 124, 456};
    cout<<woodCut(L, 7)<<endl;
    return 0;
}
