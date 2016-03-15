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

vector<string> wordSearchII(vector<vector<char> > &board, vector<string> &words){
    vector<string> res;
    return res;
}

int main(){
    vector<vector<char> > board = {
        {'d','o','a','f'},
        {'a','g','a','i'},
        {'d','c','a','n'}
    };
    vector<string> words = {"dog", "dad", "dgdg", "can", "again"};
    vector<string> res = wordSearchII(board, words);
    for(string s : res) cout<<s<<endl;
    return 0;
}