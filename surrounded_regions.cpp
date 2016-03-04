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

pair<int,int> f(vector<vector<pair<int,int> > >& parent, int i, int j){
    pair<int,int> curr = make_pair(i,j);
    while(parent[curr.first][curr.second].first >= 0){
        curr = parent[curr.first][curr.second];
    }
    pair<int,int> temp = make_pair(i,j);
    while(parent[temp.first][temp.second].first >= 0){
        pair<int,int> x = parent[temp.first][temp.second];
        parent[temp.first][temp.second] = curr;
        temp = x;
    }
    return curr;
}

void u(vector<vector<pair<int,int> > >& parent, int i, int j, int a, int b){
    pair<int,int> l_p = f(parent, i, j);
    pair<int,int> r_p = f(parent, a, b);
    if(l_p == r_p && l_p.first>=0) return;
    bool boarder = 
        parent[l_p.first][l_p.second].first == -2 ||
        parent[r_p.first][r_p.second].first == -2;
    parent[l_p.first][l_p.second] = r_p;
    if(boarder) parent[r_p.first][r_p.second].first = parent[r_p.first][r_p.second].second = -2;
}

void surroundedRegions(vector<vector<char> >& board){
    if(board.size() == 0 || board[0].size() == 0) return;
    int r = board.size(), c = board[0].size();
    vector<vector<pair<int,int> > > parent(r, vector<pair<int,int> >(c, make_pair(-1,-1)));
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] == 'X') continue;
            if(i == 0 || i == r-1 || j == 0 || j == c-1)
                parent[i][j] = make_pair(-2,-2);
            if(j > 0 && board[i][j-1] == 'O')
                u(parent, i, j, i, j-1);
            if(i > 0 && board[i-1][j] == 'O')
                u(parent, i, j, i-1, j);
        }
    } 
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(board[i][j] == 'X') continue;
            pair<int,int> p = f(parent, i, j);
            p = parent[p.first][p.second];
            if(p.first == -1 && p.second == -1) board[i][j] = 'X';
        }
    }
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