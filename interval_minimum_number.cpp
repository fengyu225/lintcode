/*
Given an integer array (index from 0 to n-1, where n is the size of this array), and an query list. Each query has two integers [start, end]. For each query, calculate the minimum number between index start and end in the given array, return the result list.

Example
For array [1,2,7,8,5], and queries [(1,2),(0,4),(2,4)], return [2,1,5]

Note
We suggest you finish problem Segment Tree Build, Segment Tree Query and Segment Tree Modify first.

Challenge
O(logN) time for each query
*/

#include "header.h"

class SegmentTreeNodeMin {
    public:
        int min_v;
        int start, end;
        SegmentTreeNodeMin* left, *right;
        SegmentTreeNodeMin(int s, int e):min_v(0),start(s),end(e),left(NULL),right(NULL) {}
};

SegmentTreeNodeMin* build_helper(int start, int end, vector<int>& A){
    if(start>end) return NULL;
    SegmentTreeNodeMin* root = new SegmentTreeNodeMin(start, end);
    if(start == end){
        root->min_v = A[start];
        return root;
    }
    int m = start+(end-start)/2;
    SegmentTreeNodeMin* l = build_helper(start, m, A);
    SegmentTreeNodeMin* r = build_helper(m+1, end, A);
    root->left = l;
    root->right = r;
    root->min_v = min(l->min_v, r->min_v);
    return root;
}

SegmentTreeNodeMin* build(vector<int>& A){
    return build_helper(0, A.size()-1, A); 
}

int query(SegmentTreeNodeMin* root, int start, int end){
    if(start<=root->start && end>=root->end) return root->min_v;
    int m = root->start+(root->end-root->start)/2;
    if(start>m) return query(root->right, start, end);
    if(end<=m) return query(root->left, start, end);
    return min(query(root->left, start, m), query(root->right, m+1, end));
}

vector<int> intervalMinNumber(vector<int> &A, vector<Interval> &queries){
    int sz = A.size();
    vector<int> res;
    if(sz == 0) return res;
    SegmentTreeNodeMin* root = build(A);
    for(Interval i:queries){
        res.push_back(query(root, i.start, i.end));
    }
    return res;
}

int main(){
    vector<int> nums = {1, 2, 7, 8, 5};
    vector<Interval> queries = {
        {1, 2},
        {0, 4},
        {2, 4}
    };
    vector<int> res = intervalMinNumber(nums, queries);
    print_vector<int>(res);
    return 0;
}