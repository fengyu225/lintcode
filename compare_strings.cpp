/*
Compare two strings A and B, determine whether A contains all of the characters in B.

The characters in string A and B are all Upper Case letters.

 Notice

The characters of B in A are not necessary continuous or ordered.

Example
For A = "ABCD", B = "ACD", return true.

For A = "ABCD", B = "AABC", return false.
*/

#include "header.h"

bool compareStrings(string A, string B) {
    int a_len = A.length();
    if(a_len == 0) return B.length() == 0;
    vector<int> arr(26, 0);
    for(char c : A) arr[c-'A']++;
    for(char c : B){
        if(arr[c-'A'] == 0) return false;
        arr[c-'A']--;
    }
    return true;
}

int main(){
    cout<<compareStrings("ABCD", "ACD")<<endl;
    cout<<compareStrings("ABCD", "AABC")<<endl;
    return 0;
}
