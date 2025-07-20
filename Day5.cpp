// Leetcode 790. Domino and Tromino Tiling
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M = 1e9 + 7;
    int numTilings(int n) {
        if(n == 1 || n == 2)    return n;
        vector<int>dp(n+1,-1);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;
        for(int i = 4;i<=n;i++) {
            dp[i] = (2*dp[i-1] % M + dp[i-3] % M) % M;
        }
        return dp[n];
    }
};