// Leetcode 2901. Longest Unequal Adjacent Groups Subsequence II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkHammer(string& s1,string& s2) {
        int diff = 0;
        for(int i = 0;i<s1.size();i++) {
            if(s1[i] != s2[i])  diff++;
            if(diff>1)  return false;
        }
        return diff == 1;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        // if(words.size() == 1)   return words;
        int n = words.size();
        vector<int>dp(n,1);
        vector<int>parent(n,-1);
        int longSub = 1;
        int longSubIdx = 0;
        for(int i = 0;i<n;i++) {
            for(int j = 0;j<i;j++) {
                if(groups[i] != groups[j] && words[i].size() == words[j].size() && checkHammer(words[i],words[j])) {
                    if(dp[i]<dp[j]+1) {
                        dp[i] = dp[j] +1;
                        parent[i] = j;
                    }
                    if(longSub <dp[i]) {
                        longSub = dp[i];
                        longSubIdx = i;
                    }
                }
            }
        }
        vector<string> ans;
        while(longSubIdx != -1) {
            ans.push_back(words[longSubIdx]);
            longSubIdx = parent[longSubIdx];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};