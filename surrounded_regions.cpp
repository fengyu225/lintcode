/*
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O''s into 'X''s in that surrounded region.

X X X X
X O O X
X X O X
X O X X

After capture all regions surrounded by 'X', the board should be:

X X X X
X X X X
X X X X
X O X X
*/

#include "header.h"

/* using BFS
void setBoarder(vector<vector<char> >& board, int i, int j, int r, int c){
    if(board[i][j] != 'O') return;
    board[i][j] = 'G';
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    int move[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    while(!q.empty()){
        pair<int,int> temp = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int new_x = move[i][0]+temp.first;
            int new_y = move[i][1]+temp.second;
            if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && board[new_x][new_y] == 'O'){
                board[new_x][new_y] = 'G';
                q.push(make_pair(new_x, new_y));
            }
        }
    }
} 

void surroundedRegions(vector<vector<char> >& board) {
    if(board.size() == 0 || board[0].size() == 0) return;
    int r = board.size(), c = board[0].size();
    for(int i=0; i<c; i++){
        setBoarder(board, 0, i, r, c);
        setBoarder(board, r-1, i, r, c);
    }
    for(int i=0; i<r; i++){
        setBoarder(board, i, 0, r, c);
        setBoarder(board, i, c-1, r, c);
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] == 'G') board[i][j] = 'O';
            else board[i][j] = 'X';
        }
    } 
}   
*/

void surroundedRegions(vector<vector<char>>& board){

}

int main(){
    vector<vector<char> > board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    surroundedRegions(board);
    for(auto v : board) print_vector<char>(v);
    return 0;
}