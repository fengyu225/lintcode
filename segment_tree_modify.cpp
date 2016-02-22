/*
For a Maximum Segment Tree, which each node has an extra value max to store the maximum value in this node's interval.

Implement a modify function with three parameter root, index and value to change the node's value with [start, end] = [index, index] to the new given value. Make sure after this change, every node in segment tree still has the max attribute with the correct value.

Example
For segment tree:

                      [1, 4, max=3]
                    /                \
        [1, 2, max=2]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=3]

if call modify(root, 2, 4), we can get:

                      [1, 4, max=4]
                    /                \
        [1, 2, max=4]                [3, 4, max=3]
       /              \             /             \
[1, 1, max=2], [2, 2, max=4], [3, 3, max=0], [4, 4, max=3]

or call modify(root, 4, 0), we can get:

                      [1, 4, max=2]
                    /                \
        [1, 2, max=2]                [3, 4, max=0]
       /              \             /             \
[1, 1, max=2], [2, 2, max=1], [3, 3, max=0], [4, 4, max=0]

Note
We suggest you finish problem Segment Tree Build and Segment Tree Query first.

Challenge
Do it in O(h) time, h is the height of the segment tree.
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

void modify(SegmentTreeNode *root, int index, int value) {
    if(!root) return;
    if(root->start == index && root->end == index){
        root->max = value;
        return;
    }
    int m = root->start+(root->end-root->start)/2;
    if(index<=m) modify(root->left, index, value);
    if(index>m) modify(root->right, index, value);
    root->max = max(root->left?root->left->max:INT_MIN, root->right?root->right->max:INT_MIN);
}

int main(){
    vector<int> nums = {2, 1, 3, 4};
    SegmentTreeNode* root = build(nums);
    printSegmentTree(root);
    modify(root, 2, 4);
    cout<<endl;
    printSegmentTree(root);
    return 0;
}