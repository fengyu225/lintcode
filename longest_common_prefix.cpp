/*
Given k strings, find the longest common prefix (LCP).

Have you met this question in a real interview? Yes
Example
For strings "ABCD", "ABEF" and "ACEF", the LCP is "A"

For strings "ABCDEFG", "ABCEFG" and "ABCEFA", the LCP is "ABC"
*/

#include "header.h"

string longestCommonPrefix(vector<string> &strs) {
    int len = strs.size();
    string res = "";
    if(len == 0) return res;
    int curr = 0;
    while(1){
        if(curr == (int)strs[0].length()) return res;
        char c = strs[0][curr];
        for(int i=1; i<len; i++){
            if(curr == (int)strs[0].length() || c != strs[i][curr]) return res;
        }
        res.push_back(c);
        curr++;
    }
    return res;
}

int main(){
    vector<string> strs = {"ABCDEFG", "ABCEFG", "ABCEFA"};
    cout<<longestCommonPrefix(strs)<<endl;
    return 0;
}
