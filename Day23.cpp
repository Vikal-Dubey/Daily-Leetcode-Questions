// Leetcode 3068. Find the Maximum Sum of Node Values
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long ans = 0,count = 0;
        long long discardedNode = INT_MAX;
        for(long long num : nums) {
            ans += max(num,num^k);
            count += ((num^k)>num);
            discardedNode = min(discardedNode,abs(num-(num^k)));
        }
        return count%2==0?ans:(ans-discardedNode);
    }
};