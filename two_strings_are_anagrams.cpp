/*
Write a method anagram(s,t) to decide if two strings are anagrams or not.
Clarification
What is Anagram?
- Two strings are anagram if they can be the same after change the order of characters.

Example
Given s = "abcd", t = "dcab", return true.
Given s = "ab", t = "ab", return true.
Given s = "ab", t = "ac", return false.
*/

#include "header.h"

bool anagram(string s, string t) {
    if(s.length() != t.length()) return false;
    vector<int> arr(256, 0);
    for(char c : s) arr[c]++;
    for(char c : t){
        if(arr[c] == 0) return false;
        arr[c]--;
    }
    return true;
}

int main(){
    cout<<anagram("abcd", "dcab")<<endl;
    cout<<anagram("ab", "ab")<<endl;
    cout<<anagram("ab", "ac")<<endl;
    return 0;
}
