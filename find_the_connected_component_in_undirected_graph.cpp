/*
Find the number connected component in the undirected graph. Each node in the graph contains a label and a list of its neighbors. (a connected component (or just component) of an undirected graph is a subgraph in which any two vertices are connected to each other by paths, and which is connected to no additional vertices in the supergraph.)

Given graph:

A------B  C
 \     |  | 
  \    |  |
   \   |  |
    \  |  |
      D   E

Return {A,B,D}, {C,E}. Since there are two connected component which is {A,B,D}, {C,E}
*/

#include "header.h"

//struct UndirectedGraphNode {
//    int label;
//    vector<UndirectedGraphNode *> neighbors;
//    UndirectedGraphNode(int x) : label(x) {};
//};

int f(map<int,int>& parent, int i){
    if(parent[i] == i) return i;
    int curr = i;
    while(parent[curr] != curr) curr = parent[curr];
    while(parent[i] != i){
        int temp = parent[i];
        parent[i] = curr;
        i = temp;
    }
    return curr;
}

void u(map<int,int>& parent, int i, int j, int& sz){
    int i_p = f(parent, i);
    int j_p = f(parent, j);
    if(i_p == j_p) return;
    sz--;
    if(i_p<j_p) parent[j_p] = i_p;
    else parent[i_p] = j_p;
}

vector<vector<int> > connectedSet(vector<UndirectedGraphNode*>& nodes) {
    vector<vector<int> > res;
    int sz = nodes.size();
    if(sz == 0) return res;
    map<int,int> parent;
    map<int,vector<int> > mp;
    int cnt = sz;
    for(UndirectedGraphNode* n : nodes) parent[n->label] = n->label; 
    for(UndirectedGraphNode* n : nodes){
        for(UndirectedGraphNode* m : n->neighbors){
            u(parent, n->label, m->label, cnt);
        }
    }
    for(auto n : nodes){
        int n_p = f(parent, n->label);
        mp[n_p].push_back(n->label);
    } 
    for(auto p : mp) res.push_back(p.second);
    return res;
}

int main(){
    UndirectedGraphNode* a = new UndirectedGraphNode(0);        
    UndirectedGraphNode* b = new UndirectedGraphNode(1);        
    UndirectedGraphNode* c = new UndirectedGraphNode(2);        
    UndirectedGraphNode* d = new UndirectedGraphNode(3);        
    UndirectedGraphNode* e = new UndirectedGraphNode(4);        
    a->neighbors.push_back(b);
    b->neighbors.push_back(a);
    b->neighbors.push_back(d);
    d->neighbors.push_back(b);
    c->neighbors.push_back(e);
    e->neighbors.push_back(c);
    vector<UndirectedGraphNode*> nodes = {a, b, c, d, e};
    vector<vector<int> > res = connectedSet(nodes);
    for(auto i:res) print_vector<int>(i);
    return 0;
}