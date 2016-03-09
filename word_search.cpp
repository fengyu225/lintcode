/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Given board = 
[
  "ABCE",
  "SFCS",
  "ADEE"
]

word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

#include "header.h"

bool exist(vector<vector<char> > &board, string word) {

}

int main(){
    vector<vector<char> > board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'},
    };
    cout<<exist(board, "ABCCED")<<endl;
    cout<<exist(board, "SEE")<<endl;
    cout<<exist(board, "ABCB")<<endl;
    return 0;
}