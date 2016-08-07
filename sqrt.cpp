/*
Implement int sqrt(int x).

Compute and return the square root of x.

Example
sqrt(3) = 1

sqrt(4) = 2

sqrt(5) = 2

sqrt(10) = 3
*/

#include "header.h"

int sqrt(int x) {
    int l = 1, r = x;
    if(x == 0) return 0;
    while(l+1<r){
        int m = l+(r-l)/2;
        if(x%m == 0 && x/m == m) return m;
        else if(m<=x/m) l = m;
        else r = m-1;
    }
    cout<<l<<" "<<r<<endl;
    return x/r>=r?r:l;
}

int main(){
    cout<<sqrt(4187)<<endl;
//    cout<<sqrt(3)<<endl;
//    cout<<sqrt(4)<<endl;
//    cout<<sqrt(5)<<endl;
//    cout<<sqrt(10)<<endl;
    return 0;
}
