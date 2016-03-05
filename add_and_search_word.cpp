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

class TNode{
        char val;
        vector<TNode*> children;
    public:
        TNode(char c):val(c){
            this->children = vector<TNode*>(28, NULL);
        }
        TNode* addChild(char c){
            this->children[c-'a'] = new TNode(c);
            return this->children[c-'a'];
        }
        TNode* getChild(char c){
            return this->children[c-'a']; 
        }
        vector<TNode*> getChildren(){
            return this->children;
        }
        bool inChildren(char c){
            return this->children[c-'a'] != NULL;
        }
        bool isLeaf(){
            return inChildren('a'+27);
        }
};

class T{
    TNode* root;
        bool search(TNode* root, string& key, int i){
            if(root == NULL) return false;
            if(i == key.length()) return root->inChildren('a'+27);
            if(key[i] != '.') return search(root->getChild(key[i]), key, i+1);
            vector<TNode*> children = root->getChildren();
            for(TNode* n : children){
                if(n == NULL) continue;
                if(search(n, key, i+1)) return true;
            }
            return false;
        }
    public:
        T(){
            root = new TNode('a'+26);
        }
        void insert(string s){
            TNode* curr = root;
            for(char c : s){
                if(curr->inChildren(c)) curr = curr->getChild(c);
                else curr = curr->addChild(c);
            }
            curr->addChild('a'+27);
        }
        TNode* getRoot(){
            return this->root;
        }
        bool search(string key){
            return search(this->root, key, 0);      
        }
};

class WordDictionary {
    T* tree;
public:

    WordDictionary(){
        this->tree = new T();
    }

    // Adds a word into the data structure.
    void addWord(string word) {
        // Write your code here
        tree->insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        // Write your code here
        return tree->search(word); 
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");

int main(){
    WordDictionary wd;
    wd.addWord("a");
    wd.addWord("a");
    cout<<wd.search(".")<<endl;
    cout<<wd.search("a")<<endl;
    cout<<wd.search("aa")<<endl;
    cout<<wd.search("a")<<endl;
    cout<<wd.search(".a")<<endl;
    cout<<wd.search("a.")<<endl;
    return 0;
}