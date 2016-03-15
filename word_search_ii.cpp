/*
Given a matrix of lower alphabets and a dictionary. Find all words in the dictionary that can be found in the matrix. A word can start from any position in the matrix and go left/right/up/down to the adjacent position. 

Given a matrix:

doaf
agai
dcan

and dictionary 

{"dog", "dad", "dgdg", "can", "again"}

return {"dog", "dad", "can", "again"}
*/

#include "header.h"

class TNode{
    private:
        vector<TNode*> children;
        char c;
    public:
        TNode(char v){
            c = v; 
            children = vector<TNode*>(28, NULL);
        } 
        TNode* getChild(char c){
            return this->children[c-'a'];
        }
        bool isLeaf(){
            return this->getChild('a'+27) != NULL;
        }
        TNode* addChild(char c){
            TNode* n = new TNode(c);
            this->children[c-'a'] = n;
            return n;
        }
};

class T{
    public:
        TNode* root;
        T(){
            root = new TNode('a'+26);
        }
        void insert(string s){
            TNode* curr = root;
            for(char c : s){
                if(curr->getChild(c) != NULL) curr = curr->getChild(c);
                else curr = curr->addChild(c);
            }
            curr->addChild('a'+27);
        } 
};

void search(
        vector<vector<char> >& board, int r, int c, int i, int j,
        unordered_set<string>& words_set, string& curr_word,
        TNode* curr,
        unordered_set<string>& has_found,
        vector<vector<bool> >& visited
        ){
//    cout<<i<<","<<j<<" "<<board[i][j]<<" "<<curr->isLeaf()<<" "<<curr_word<<endl;
    TNode* new_curr = curr->getChild(board[i][j]);
    if(new_curr == NULL) return;
    curr_word += board[i][j];
    curr = new_curr;
    visited[i][j] = true;
    if(new_curr->isLeaf()){
        words_set.erase(curr_word);
        has_found.insert(curr_word);
    }
    int move[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    for(int temp=0; temp<4; temp++){
        int new_x = move[temp][0]+i;
        int new_y = move[temp][1]+j;
        if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && visited[new_x][new_y] == false){
            search(board, r, c, new_x, new_y, words_set, curr_word, curr, has_found, visited);
        }
    }
    visited[i][j] = false;
    curr_word.pop_back();
}

vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words){
    vector<string> res;
    if(board.size() == 0 || board[0].size() == 0 || words.size() == 0) return res;
    int r = board.size(), c = board[0].size();
    T t;
    TNode* curr = t.root;
    string curr_word = "";
    unordered_set<string> words_set, has_found;
    for(string s : words){
        t.insert(s);
        words_set.insert(s);
    }
    vector<vector<bool> > visited(r, vector<bool>(c, false));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(words_set.size() == 0) break;
            if(curr->isLeaf()){
                words_set.erase(curr_word);
                has_found.insert(curr_word);
            }
            search(board, r, c, i, j, words_set, curr_word, curr, has_found, visited);
            curr_word = "";
            curr = t.root;
        }
    }
    for(string s:has_found) res.push_back(s);
    return res;
}

int main(){
//    vector<vector<char> > board = {
//        {'d','o','a','f'},
//        {'a','g','a','i'},
//        {'d','c','a','n'}
//    };
//    vector<string> words = {"dog", "dad", "dgdg", "can", "again"};
    vector<vector<char> > board = {
        {'a','b','c','e'},
        {'s','f','e','s'},
        {'a','d','e','e'}
    };
    vector<string> words = {"abceseeefs","abceseedasfe"};
    vector<string> res = wordSearchII(board, words);
    for(string s : res) cout<<s<<endl;
    return 0;
}