// Leetcode 1931. Painting a Grid With Three Different Colors
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string>columnStates;
    int M = 1e9 + 7;
    vector<vector<int>>dp;
    void generateColState(string curr,char prevChar,int l,int m) {
        if(l == m) {
            columnStates.push_back(curr);
            return;
        }
        for(char ch : {'R','B','G'}) {
            if(prevChar == ch)  continue;
            generateColState(curr+ch,ch,l+1,m);
        }
    }
    int solve(int remainCols,int prevIdx,int m) {
        if(remainCols == 0) {
            return 1;
        }
        if(dp[remainCols][prevIdx] != -1)  return dp[remainCols][prevIdx];
        int ways = 0;
        string prevState = columnStates[prevIdx];

        for(int i = 0;i<columnStates.size();i++) {
            if(i == prevIdx)    continue;

            string currState = columnStates[i];
            bool valid = true;
            for(int j = 0;j<m;j++) {
                if(currState[j] == prevState[j]) {
                    valid = false;
                    break;
                }
            }
            if(valid) {
                ways = (ways + solve(remainCols-1,i,m)) % M;
            } 
        }
        return dp[remainCols][prevIdx] =  ways;
    }
    int colorTheGrid(int m, int n) {
        generateColState("",'!',0,m);
        int result = 0;
        int totalStates = columnStates.size();
        dp = vector<vector<int>>(n+1,vector<int>(totalStates+1,-1));
        for(int i = 0;i<columnStates.size();i++) {
            result = (result+solve(n-1,i,m)) % M;
        }
        return result;
    }
};