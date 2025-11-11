#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<string>& strs, int& m, int& n,int z,int o,int i,vector<vector<vector<int>>>& dp) {
        if(i >= strs.size() || z > m || o > n) {
            return 0;
        }
        if(dp[z][o][i] != -1) {
            return dp[z][o][i];
        }
        int skip = solve(strs,m,n,z,o,i+1,dp);
        int tz = 0;
        int to = 0;
        for(int j = 0; j < strs[i].size(); j++) {
            if(strs[i][j] == '0')   tz++;
            else to++;
        }
        int take = 0;
        if(z + tz <= m && o + to <= n) {
            take = 1+solve(strs,m,n,z+tz,o+to,i+1,dp);
        }
        return dp[z][o][i] = max(take,skip);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(s+1,-1)));
        return solve(strs,m,n,0,0,0,dp);
    }
};