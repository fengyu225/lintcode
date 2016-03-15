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

bool search(vector<vector<char> > &board, string &word, vector<vector<bool> > &mask, int idx, int x, int y) {
    if (word[idx] == board[x][y]) {
        ++idx;
        if (idx == word.length()){
            return true;
        }
    } else {
        return false;
    }
    mask[x][y] = false;
    int move[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int r = board.size(), c = board[0].size();
    for(int i=0; i<4; i++){
        int new_x = move[i][0]+x;
        int new_y = move[i][1]+y;
        if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && mask[new_x][new_y] && board[new_x][new_y] == word[idx]){
            if(search(board, word, mask, idx, new_x, new_y)) return true;
        }
    }
    mask[x][y] = true;
    return false;
}

bool exist(vector<vector<char> > &board, string word) {
    if(board.size() == 0 || board[0].size() == 0) return false;
    int r = board.size(), c = board[0].size();
    vector<vector<bool> > visited(r, vector<bool>(c, true));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(search(board, word, visited, 0, i, j)) return true;
        }
    }
    return false;
}

int main(){
/*
["ABCE","SFES","ADEE"], "ABCESEEEFS"]
*/
    vector<vector<char> > board = {
        {'A','B','C','E'},
        {'S','F','E','S'},
        {'A','D','E','E'},
    };
    cout<<exist(board, "ABCESEEEFS")<<endl;
//    cout<<exist(board, "ABCCED")<<endl;
//    cout<<exist(board, "SEE")<<endl;
//    cout<<exist(board, "ABCB")<<endl;
    return 0;
}