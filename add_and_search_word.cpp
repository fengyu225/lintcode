/*
Design a data structure that supports the following two operations: addWord(word) and search(word)

search(word) can search a literal word or a regular expression string containing only letters a-z or ..

A . means it can represent any one letter.

You may assume that all words are consist of lowercase letters a-z.

addWord("bad")
addWord("dad")
addWord("mad")
search("pad")  // return false
search("bad")  // return true
search(".ad")  // return true
search("b..")  // return true
*/

#include "header.h"

class WordDictionary {
public:

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    cout<<wd.search("pad")<<endl;
    cout<<wd.search("bad")<<endl;
    cout<<wd.search(".ad")<<endl;
    cout<<wd.search("b..")<<endl;
    return 0;
}