// Leetcode 2359. Find Closest Node to Given Two Nodes
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    void bfs(vector<int>& dis,int node,vector<int>& edges) {
        vector<bool> visited(n,false);
        queue<int>q;
        q.push(node);
        dis[node] = 0;
        visited[node] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            int v = edges[u];
            if(v!=-1 && !visited[v]) {
                visited[v] = true;
                dis[v] = 1+dis[u];
                q.push(v);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n = edges.size();
        vector<int>dis1(n,INT_MAX);
        vector<int>dis2(n,INT_MAX);

        bfs(dis1,node1,edges);
        bfs(dis2,node2,edges);

        int minDisNode = -1;
        int minDis = INT_MAX;
        for(int i = 0;i<n;i++) {
            int maxD = max(dis1[i],dis2[i]);
            if(minDis>maxD) {
                minDis = maxD;
                minDisNode = i;
            }
        }
        return minDisNode;;
    }
};