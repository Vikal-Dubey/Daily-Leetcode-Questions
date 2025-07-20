// Leetcode 1061. Lexicographically Smallest Equivalent String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char dfs(char currCh,unordered_map<char,vector<char>>& adj,vector<int>& visited) {
        visited[currCh - 'a'] = 1;
        char minChar = currCh;
        for(char v : adj[currCh]) {
            if(visited[v-'a'] == 0) {
                minChar = min(minChar,dfs(v,adj,visited));
            }
        }
        return minChar;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(),m = baseStr.size();
        unordered_map<char,vector<char>>adj;
        for(int i = 0;i<n;i++) {
            char u = s1[i],v = s2[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        string result;
        for(int i = 0;i<m;i++) {
            char ch = baseStr[i];
            vector<int>visited(26,0);
            char minChar = dfs(ch,adj,visited);
            result.push_back(minChar);
        }
        return result;
    }
};