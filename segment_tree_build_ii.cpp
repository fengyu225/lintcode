/*
The structure of Segment Tree is a binary tree which each node has two attributes start and end denote an segment / interval.

start and end are both integers, they should be assigned in following rules:

    The root's start and end is given by build method.
    The left child of node A has start=A.left, end=(A.left + A.right) / 2.
    The right child of node A has start=(A.left + A.right) / 2 + 1, end=A.right.
    if start equals to end, there will be no children for this node.

Implement a build method with a given array, so that we can create a corresponding segment tree with every node value represent the corresponding interval max value in the array, return the root of this segment tree.

Example

Given [3,2,1,4]. The segment tree will be:

                 [0,  3] (max = 4)
                  /            \
        [0,  1] (max = 3)     [2, 3]  (max = 4)
        /        \               /             \
[0, 0](max = 3)  [1, 1](max = 2)[2, 2](max = 1) [3, 3] (max = 4)


Clarification

Segment Tree (a.k.a Interval Tree) is an advanced data structure which can support queries like:

    which of these intervals contain a given point
    which of these points are in a given interval

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

int main(){
    vector<int> nums = {3, 2, 1, 4};
    SegmentTreeNode* root = build(nums);
    printSegmentTree(root);
    return 0;
}