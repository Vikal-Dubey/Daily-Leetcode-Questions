// Leetcode 3373. Maximize the Number of Target Nodes After Connecting Trees II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    unordered_map<int,vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        for(auto edge : edges) {
            int u = edge[0],v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return adj;
    }
    void dfs(int curr,unordered_map<int,vector<int>>& adj,int parent,int &zeroMarkedCount,int &oneMarkedCount,vector<int>& mark) {
        if(mark[curr] == 0) {
            zeroMarkedCount++;
        } else {
            oneMarkedCount++;
        }
        for(auto ngbr : adj[curr]) {
            if(ngbr!=parent) {
                mark[ngbr] = (mark[curr] == 0)?1:0;
                dfs(ngbr,adj,curr,zeroMarkedCount,oneMarkedCount,mark); 
            }
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size()+1;
        int m = edges2.size()+1;
        unordered_map<int,vector<int>>adjA = getAdj(edges1);
        unordered_map<int,vector<int>>adjB = getAdj(edges2);

        vector<int>markA(n,-1);
        markA[0] = 0;
        int zeroMarkedCountA = 0,oneMarkedCountA = 0;
        dfs(0,adjA,-1,zeroMarkedCountA,oneMarkedCountA,markA);


        vector<int>markB(m,-1);
        markB[0] = 0;
        int zeroMarkedCountB = 0,oneMarkedCountB = 0;
        dfs(0,adjB,-1,zeroMarkedCountB,oneMarkedCountB,markB);

        int maxCountB = max(zeroMarkedCountB,oneMarkedCountB);
        
        vector<int>result(n);
        for(int i = 0;i<n;i++) {
            result[i] = ((markA[i]==0)?zeroMarkedCountA:oneMarkedCountA) + maxCountB;
        }
        return result;
    }
};