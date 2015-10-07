/*
Count the number of k's between 0 and n. k can be 0 - 9.


Example
if n=12, k=1 in [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12], we have FIVE 1's (1, 10, 11, 12)
*/

#include "header.h"

int digitCounts(int k, int n) {
    if(n<=0) return 0;
    if(n<10) return 1;
    int y = 1, temp = n;
    for(;temp>=10;y*=10, temp/=10);
    if(n/y == k) return n-n/y*y+1+n/y*digitCounts(k, y-1)+digitCounts(k, n-n/y*y);
    else if(n/y<k) return n/y*digitCounts(k, y-1)+digitCounts(k, n-n/y*y);
    else // n/y>k
        return (k==0?0:y)+n/y*digitCounts(k, y-1)+digitCounts(k, n-n/y*y);
}

int main(){
//    cout<<digitCounts(1, 12)<<endl;
    cout<<digitCounts(0, 12)<<endl;
    return 0;
}
