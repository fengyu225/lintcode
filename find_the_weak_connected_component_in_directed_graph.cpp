/*
Find the number Weak Connected Component in the directed graph. Each node in the graph contains a label and a list of its neighbors. (a connected set of a directed graph is a subgraph in which any two vertices are connected by direct edge path.)

Sort the element in the set in increasing order

Given graph:

A----->B  C
 \     |  | 
  \    |  |
   \   |  |
    \  v  v
     ->D  E <- F

Return {A,B,D}, {C,E,F}. Since there are two connected component which are {A,B,D} and {C,E,F}
*/

#include "header.h"

/*
struct DirectedGraphNode {
    int label;
    vector<DirectedGraphNode *> neighbors;
    DirectedGraphNode(int x) : label(x) {};
};
*/

int f(map<int,int>& parent, int i){
    if(parent[i] == -1) return i;
    int curr = i;
    while(parent[curr] != -1) curr = parent[curr];
    while(parent[i] != -1){
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

vector<vector<int> > connectedSet2(vector<DirectedGraphNode*>& nodes) {
    vector<vector<int> > res;
    int sz = nodes.size();
    if(sz == 0) return res;
    map<int,int> parent;
    map<int,vector<int> > mp;
    int cnt = sz;
    for(DirectedGraphNode* n : nodes) parent[n->label] = -1; 
    for(DirectedGraphNode* n : nodes){
        for(DirectedGraphNode* m : n->neighbors){
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
//    DirectedGraphNode* a = new DirectedGraphNode(0);        
//    DirectedGraphNode* b = new DirectedGraphNode(1);        
//    DirectedGraphNode* c = new DirectedGraphNode(2);        
//    DirectedGraphNode* d = new DirectedGraphNode(3);        
//    DirectedGraphNode* e = new DirectedGraphNode(4);        
//    DirectedGraphNode* f = new DirectedGraphNode(5);        
//    a->neighbors.push_back(b);
//    a->neighbors.push_back(d);
//    b->neighbors.push_back(d);
//    c->neighbors.push_back(e);
//    f->neighbors.push_back(e);
//    vector<DirectedGraphNode*> nodes = {a, b, c, d, e, f};

    DirectedGraphNode* a = new DirectedGraphNode(1);        
    DirectedGraphNode* b = new DirectedGraphNode(2);        
    DirectedGraphNode* c = new DirectedGraphNode(3);        
    DirectedGraphNode* d = new DirectedGraphNode(4);        
    DirectedGraphNode* e = new DirectedGraphNode(5);        
    DirectedGraphNode* f = new DirectedGraphNode(6);        
    a->neighbors.push_back(b);
    a->neighbors.push_back(d);
    b->neighbors.push_back(d);
    c->neighbors.push_back(e);
    f->neighbors.push_back(e);
    vector<DirectedGraphNode*> nodes = {a, b, c, d, e, f};
    vector<vector<int> > res = connectedSet2(nodes);
    for(auto i : res) print_vector<int>(i);
    return 0;
}