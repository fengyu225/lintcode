/*
The code base version is an integer start from 1 to n. One day, someone committed a bad version in the code case, so it caused this version and the following versions are all failed in the unit tests. Find the first bad version.

You can call isBadVersion to help you determine which version is the first bad one. The details interface can be found in the code's annotation part.

Please read the annotation in code area to get the correct way to call isBadVersion in different language. For example, Java is SVNRepo.isBadVersion(v)

Example
Given n = 5:

isBadVersion(3) -> false
isBadVersion(5) -> true
isBadVersion(4) -> true
Here we are 100% sure that the 4th version is the first bad version.
*/

#include "header.h"

class SVNRepo {
    public:
    static bool isBadVersion(int k){
        if(k>=3) return true;
        return false;
    }
};

int findFirstBadVersion(int n) {
    if(n == 1) return 1;
    int l = 1, r = n;
    while(l+1<r){
        cout<<l<<" "<<r<<endl;
        int m = l+(r-l)/2;
        if(SVNRepo::isBadVersion(m)) r=m;
        else l = m+1;
    }
    return SVNRepo::isBadVersion(l)?l:r;
}

int main(){
    cout<<findFirstBadVersion(9)<<endl;
    return 0;
}
