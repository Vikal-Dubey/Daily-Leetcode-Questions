// Leetcode 3372. Maximize the Number of Target Nodes After Connecting Trees I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bfs(unordered_map<int,vector<int>>& adj,int k,int n,int curr) {
        queue<pair<int,int>>q;
        q.push({curr,0});
        vector<bool>visited(n,false);
        visited[curr] = true;
        int count = 0;//count the target node
        while(!q.empty()) {
            int currNode = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(dis>k)   continue;
            count++;//include the current node in target node count
            //visit neighbour of currNode
            for(auto ngbr:adj[currNode]) {
                if(!visited[ngbr]) {
                    visited[ngbr] = true;
                    q.push({ngbr,dis+1});
                }
            }
        }
        return count;
    }
    vector<int> findCount(vector<vector<int>>& edges,int k) {
        unordered_map<int,vector<int>>adj;
        int n = edges.size()+1;
        for(auto edge:edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n);
        for(int i = 0;i<n;i++) {
            result[i] = bfs(adj,k,n,i);
        }
        return result;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size()+1;
        vector<int>result1 = findCount(edges1,k);
        vector<int>result2 = findCount(edges2,k-1);
        int maxNodeCount = *max_element(result2.begin(),result2.end());
        for(int i = 0;i<result1.size();i++) {
            result1[i] += maxNodeCount;
        }
        return result1;
    }
};