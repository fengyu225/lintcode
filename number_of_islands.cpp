/*
Given a boolean 2D matrix, find the number of islands.

0 is represented as the sea, 1 is represented as the island. If two 1 is adjacent, we consider them in the same island. We only consider up/down/left/right adjacent.

Given graph:

[
  [1, 1, 0, 0, 0],
  [0, 1, 0, 0, 1],
  [0, 0, 0, 1, 1],
  [0, 0, 0, 0, 0],
  [0, 0, 0, 0, 1]
]

return 3
*/

#include "header.h"

/* using BFS
void mark(vector<vector<bool> >& grid, int i, int j, int r, int c){
    grid[i][j] = false;
    queue<pair<int,int> > q;
    q.push(make_pair(i,j));
    int move[4][2] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0}
    };
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int new_x = move[i][0]+p.first;
            int new_y = move[i][1]+p.second;
            if(new_x>=0 && new_x<r && new_y>=0 && new_y<c && grid[new_x][new_y]){
                grid[new_x][new_y] = false;
                q.push(make_pair(new_x, new_y));
            }
        }
    }
}

int numIslands(vector<vector<bool> >& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int r = grid.size(), c = grid[0].size();
    int res = 0;
    for(int i=0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(grid[i][j] == true){
                mark(grid, i, j, r, c);
                res++;
            }
        }
    }
    return res;
}
*/

pair<int,int> f(pair<int,int>& a, pair<int,int>& b){

}

int numIslands(vector<vector<bool> >& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int r = grid.size(), c = grid[0].size();
    vector<vector<int> > parents(r, vector<int>(c, -1));
    
}

int main(){
    vector<vector<bool> > grid = {
        {1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1}
    };
    cout<<numIslands(grid)<<endl;
    return 0;
}