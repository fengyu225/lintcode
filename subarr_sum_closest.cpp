/*
Given an integer array, find a subarray with sum closest to zero. Return the indexes of the first number and last number.

Have you met this question in a real interview? Yes
Example
Given [-3, 1, 1, -3, 5], return [0, 2], [1, 3], [1, 1], [2, 2] or [0, 4].
*/

#include "header.h"

class comp_inc{
    public:
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
            return a.first<b.first;
        }
};

class comp_desc{
    public:
        bool operator() (const pair<int,int>& a, const pair<int,int>& b) const{
            return a.first>b.first;
        }
};

vector<int> subarraySumClosest(vector<int> nums){
    int sz = nums.size();
    vector<int> res(2, -1);
    int diff = INT_MAX;
    set<pair<int,int>, comp_inc> s;
    set<pair<int,int>, comp_desc> t;
    int last_sum = 0;
    s.insert(make_pair(last_sum, -1));
    t.insert(make_pair(last_sum, -1));
    int start=0, end=0;
    for(int i=0; i<sz; i++){
        int curr_s = last_sum+nums[i];
        pair<int,int> p = make_pair(curr_s, i);
        auto iter = s.lower_bound(p);
        if(iter != s.end() && ((*iter).first-curr_s)<diff){
            start = (*iter).second+1;
            end = i;
            diff = (*iter).first - curr_s;
        }
        iter = t.lower_bound(p);
        if(iter != t.end() && (curr_s - (*iter).first)<diff){
            start = (*iter).second+1;
            end = i;
            diff = curr_s - (*iter).first;
        }
        if(abs(curr_s)<diff){
            diff = abs(curr_s);
            start = i;
            end = i;
        }
        s.insert(p);
        t.insert(p);
        last_sum = curr_s;
    }
    res[0] = start;
    res[1] = end;
    return res;
}

int main(){
    //vector<int> nums = {6, -4, -8, 3, 1, 7};
    vector<int> nums = {-10,-2,-3,-100,1,2,3,-1,4};
    vector<int> res = subarraySumClosest(nums);
    print_vector<int>(res);
    return 0;
}
