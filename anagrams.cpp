/*
Given an array of strings, return all groups of strings that are anagrams.

 Notice

All inputs will be in lower-case

Example
Given ["lint", "intl", "inlt", "code"], return ["lint", "inlt", "intl"].

Given ["ab", "ba", "cd", "dc", "e"], return ["ab", "ba", "cd", "dc"].
*/

#include "header.h"

string getSortedString(string &str) {
    static int count[26];
    for (int i = 0; i < 26; i++) {
        count[i] = 0;
    }
    for (int i = 0; i < str.length(); i++) {
        count[str[i] - 'a']++;
    }
    
    string sorted_str = "";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < count[i]; j++) {
            sorted_str = sorted_str + (char)('a' + i);
        }
    }
    return sorted_str;
}

vector<string> anagrams(vector<string> &strs) {
    unordered_map<string, int> hash;
    
    for (int i = 0; i < strs.size(); i++) {
        string str = getSortedString(strs[i]);
        if (hash.find(str) == hash.end()) {
            hash[str] = 1;
        } else {
            hash[str] = hash[str] + 1;
        }
    }
    
    vector<string> result;
    for (int i = 0; i < strs.size(); i++) {
        string str = getSortedString(strs[i]);
        if (hash.find(str) == hash.end()) {
            continue;
        } else {
            if (hash[str] > 1) {
                result.push_back(strs[i]);
            }
        }
    }
    return result;
}

int main(){
    vector<string> strs = {"lint", "intl", "inlt", "code"};
    vector<string> res = anagrams(strs);
    print_vector<string>(res);
    return 0;
}
