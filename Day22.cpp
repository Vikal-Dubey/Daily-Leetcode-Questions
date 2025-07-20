// Leetcode 3362. Zero Array Transformation III
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        int Q = queries.size();
        int usedQueries = 0;
        priority_queue<int>maxHeap;//to store the farthest point
        priority_queue<int,vector<int>,greater<int>>past;//past Endings of queries
        sort(queries.begin(),queries.end());
        int j = 0;//pointing to queries
        for(int i = 0;i<nums.size();i++) {
            while(j<Q && queries[j][0] == i) {
                maxHeap.push(queries[j][1]);
                j++;
            }
            nums[i] -= past.size();
            while(nums[i]>0 && maxHeap.size()>0 && maxHeap.top() >= i) {
                int ending = maxHeap.top();
                maxHeap.pop();
                past.push(ending);
                nums[i]--;
                usedQueries++;
            }
            if(nums[i]>0)   return -1;
            while(!past.empty() && past.top()<=i)    past.pop();
        }
        return Q-usedQueries;
    }
};