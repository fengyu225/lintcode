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

int numIslands(vector<vector<bool> >& grid) {
    if(grid.size() == 0 || grid[0].size() == 0) return 0;
    int r = grid.size(), c = grid[0].size();

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