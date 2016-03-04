/*
Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.

You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.

Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
*/

#include "header.h"

int f(vector<int>& parent, int i){
    if(parent[i] == -1) return i;
    int j = i;
    for(;parent[j] != -1;j = parent[j]);
    while(parent[i] != -1){
        int temp = parent[i];
        parent[i] = j;
        i = temp;
    }
    return j;
}

bool u(vector<int>& parent, int i, int j){
    int i_p = f(parent, i);
    int j_p = f(parent, j);
    if(i_p == j_p && i_p != -1) return false;
    parent[i_p] = j_p;
    return true;
}

bool validTree(int n, vector<vector<int> >& edges) {
    int c = edges.size();
    if(n != c+1) return false;
    vector<int> parent(n, -1);
    for(int i=0; i<n-1; i++){
        if(!u(parent, edges[i][0], edges[i][1])) return false; 
    }
    return true;
}

int main(){
    vector<vector<int> > edges = {
        {0, 1},
        {0, 2},
        {0, 3},
        {1, 4}
    };
    cout<<validTree(5, edges)<<endl;
    return 0;
}