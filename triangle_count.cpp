/*
Given an array of integers, how many three numbers can be found in the array, so that we can build an triangle whose three edges length is the three numbers that we find? 

Example

Given array S = [3,4,6,7], return 3. They are:

[3,4,6]
[3,6,7]
[4,6,7]

Given array S = [4,4,4,4], return 4. They are:

[4(1),4(2),4(3)]
[4(1),4(2),4(4)]
[4(1),4(3),4(4)]
[4(2),4(3),4(4)]

*/

#include "header.h"

class cmp{
    public:
        bool operator() (int a, int b){
            return a>=b;          
        }
};

int triangleCount(vector<int> &S) {
    int sz = S.size();
    if(sz < 3) return 0;
    sort(S.begin(), S.end(), cmp());
    int res = 0;
    for(int a=0; a<sz-2; a++){
        int l = a+1, r = sz-1;
        while(l<r){
            int temp = S[l]+S[r];
            if(temp>S[a]){
                res+=(r-l);
                l++;
            }
            else r--;
        }
    }
    return res;
}

int main(){
    //vector<int> nums = {3, 4, 6, 7};
    vector<int> nums = {4, 4, 4, 4};
    cout<<triangleCount(nums)<<endl;
    return 0;
}