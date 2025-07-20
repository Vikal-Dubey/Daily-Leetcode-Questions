// Leetcode 3342. Find Minimum Time to Reach Last Room II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>>directions = {{1,0},{-1,0},{0,1},{0,-1}};
    typedef pair<int,pair<int,int>>P;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m = moveTime.size();
        int n = moveTime[0].size();
        vector<vector<int>>result(m,vector<int>(n,INT_MAX));
        priority_queue<P,vector<P>,greater<P>>pq;
        result[0][0] = 0;
        pq.push({0,{0,0}});
        while(pq.size()>0){
            int currTime = pq.top().first;
            auto cell = pq.top().second;
            int x = cell.first;
            int y = cell.second;
            pq.pop();
            if(x == m-1 && y == n-1) {
                return currTime;
            }
            for(auto &dir:directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                if(x_>=0 && x_<m && y_>=0 && y_<n) {
                    int waitingTime = max(moveTime[x_][y_] - currTime,0);
                    int steps = x_+y_;
                    int count = 0;
                    if(steps%2 == 0)    count = 2;
                    else count = 1;
                    int arrTime = waitingTime + currTime +count;
                    if(result[x_][y_]>arrTime) {
                        result[x_][y_] = arrTime;
                        pq.push({arrTime,{x_,y_}});
                    }
                } 
            }
        }
        return -1;
    }
};