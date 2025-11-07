#include<bits/stdc++.h>
using namespace std;
// By DSU 
class Solution {
public:
    class DSU {
    public:
        vector<int>parent,size;
        DSU(int n) {
            parent.resize(n+1);
            size.resize(n+1);
            iota(parent.begin(),parent.end(),0);
        }D
        int find(int x) {
            return parent[x] = (parent[x] == x) ? x : find(parent[x]);
        }
        void unite(int a,int b) {
            a = find(a);
            b = find(b);
            if(a == b)  return;
            if(size[a] < size[b]) {
                parent[a] = b;
                size[b] += size[a];
            } else {
                parent[b] = a;
                size[a] += size[b];
            }
        }
    };
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,set<int>>mp;
        vector<int>ans;
        DSU dsu(c+1);
        for(auto &it : connections) {
            dsu.unite(it[0],it[1]);
        }
        for(int i = 1; i <= c; i++) {
            int id = dsu.find(i);
            mp[id].insert(i);
        }
        for(auto &it : queries) {
            int type = it[0];
            int node = it[1];
            int compo = dsu.find(node);
            if(type == 1) {
                if(mp[compo].size() > 0) {
                    if(mp[compo].count(node)) {
                        ans.push_back(node);
                    } else {
                        ans.push_back(*mp[compo].begin());
                    }
                } else {
                    ans.push_back(-1);
                }
            } else {
                mp[compo].erase(node);
            }
        }
        return ans;
    }
};

// By DFS Traversal
class Solution {
public:
    void dfs(unordered_map<int,vector<int>>& adj,int node,int compo,vector<int>& parent,unordered_map<int,set<int>>& mp,vector<int>& vis) {
        parent[node] = compo;
        vis[node] = 1;
        mp[compo].insert(node);
        for(auto &it : adj[node]) {
            if(!vis[it]) {
                dfs(adj,it,compo,parent,mp,vis);
            }
        }
    }
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        unordered_map<int,set<int>>mp;
        vector<int>vis(c+1,0);
        vector<int>parent(c+1);
        vector<int>ans;
        unordered_map<int,vector<int>>adj;
        for(auto &it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= c; i++) {
            if(!vis[i]) {
                dfs(adj,i,i,parent,mp,vis);
            }
        }
        for(auto &it : queries) {
            int compo = parent[it[1]];
            if(it[0] == 1) {
                if(mp[compo].size() > 0) {
                    if(mp[compo].count(it[1])) {
                        ans.push_back(it[1]);
                    } else {
                        ans.push_back(*mp[compo].begin());
                    }
                } else {
                    ans.push_back(-1);
                }
            } else {
                mp[compo].erase(it[1]);
            }
        }
        return ans;
    }
};