/*
For an integer array (index from 0 to n-1, where n is the size of this array), in the corresponding SegmentTree, each node stores an extra attribute max to denote the maximum number in the interval of the array (index from start to end).

Design a query method with three parameters root, start and end, find the maximum number in the interval [start, end] by the given root of segment tree.

Example

For array [1, 4, 2, 3], the corresponding Segment Tree is:

                  [0, 3, max=4]
                 /             \
          [0,1,max=4]        [2,3,max=3]
          /         \        /         \
   [0,0,max=1] [1,1,max=4] [2,2,max=2], [3,3,max=3]

query(root, 1, 1), return 4

query(root, 1, 2), return 4

query(root, 2, 3), return 3

query(root, 0, 2), return 4
Note

It is much easier to understand this problem if you finished Segment Tree Build first.
*/

#include "header.h"

SegmentTreeNode* build_helper(int start, int end, vector<int>& A){
    if(start>end) return NULL;
    SegmentTreeNode* root = new SegmentTreeNode(start, end);
    if(start == end){
        root->max = A[start];
        return root;
    }
    int m = start+(end-start)/2;
    SegmentTreeNode* l = build_helper(start, m, A);
    SegmentTreeNode* r = build_helper(m+1, end, A);
    root->left = l;
    root->right = r;
    root->max = max(l->max, r->max);
    return root;
}

SegmentTreeNode * build(vector<int>& A) {
    int sz = A.size();
    if(sz == 0) return NULL;
    return build_helper(0, sz-1, A);
}

int query(SegmentTreeNode *root, int start, int end) {
    if(start<=root->start && end>=root->end) return root->max;
    int m = root->start+(root->end-root->start)/2;
    if(start>m) return query(root->right, start, end);
    if(end<=m) return query(root->left, start, end);
    return max(query(root->left, start, m), query(root->right, m+1, end));
}

int main(){
    vector<int> nums = {1, 4, 2, 3};
    SegmentTreeNode* root = build(nums);
    cout<<query(root, 1, 1)<<endl;
    cout<<query(root, 1, 2)<<endl;
    cout<<query(root, 2, 3)<<endl;
    cout<<query(root, 0, 2)<<endl;
    return 0;
}