/*
Given a string and an offset, rotate string by offset. (rotate from left to right)


Example
Given "abcdefg".

offset=0 => "abcdefg"
offset=1 => "gabcdef"
offset=2 => "fgabcde"
offset=3 => "efgabcd"
Challenge
Rotate in-place with O(1) extra memory.
*/

#include "header.h"

void rotateString(string &str,int offset){
    int sz = str.length();
    if(sz == 0) return;
    offset = offset%sz;
    if(offset == 0) return;
    reverse(str.begin(), str.end());
    reverse(str.begin(), str.begin()+offset);
    reverse(str.begin()+offset, str.end());
}

int main(){
    string str = "abcdefg";
    rotateString(str, 3);
    cout<<str<<endl;
    return 0;
}
