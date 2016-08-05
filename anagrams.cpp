/*
Given an array of strings, return all groups of strings that are anagrams.

 Notice

All inputs will be in lower-case

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].
*/

#include "header.h"

vector<string> anagrams(vector<string> &strs) {
    vector<string> res;
    return res;
}

int main(){
    vector<string> strs = {"lint", "intl", "inlt", "code"};
    vector<string> res = anagrams(strs);
    print_vector<string>(res);
    return 0;
}
