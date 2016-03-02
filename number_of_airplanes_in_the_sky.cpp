/*
Given an interval list which are flying and landing time of the flight. How many airplanes are on the sky at most?

If landing and flying happens at the same time, we consider landing should happen at first.

For intervals list:

[
  [1,10],
  [2,3],
  [5,8],
  [4,7]
]

Return 3
*/

#include "header.h"

class comp{
    public:
        bool operator() (pair<int,int> a, pair<int,int> b){
            return a.first<b.first || (a.first == b.first && a.second<b.second);
        }
};

int countOfAirplanes(vector<Interval> &airplanes) {
    vector<pair<int,int> > points;
    int sz = airplanes.size();
    if(sz < 2) return sz;
    for(auto i:airplanes){
        points.push_back(make_pair(i.start,1));
        points.push_back(make_pair(i.end, -1));
    }
    sort(points.begin(), points.end(), comp());
    int res = 0, curr = 0;
    for(pair<int,int> p:points){
        if(p.second>0) curr++;
        else curr--;
        res = max(res, curr);
    }
    return res;
}

int main(){
    vector<Interval> airplanes = {
        {1, 10},
        {2, 3},
        {5, 8},
        {4, 7}
    };
    cout<<countOfAirplanes(airplanes)<<endl;
    return 0;
}