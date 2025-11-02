#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        queue<pair<int,int>>q;
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(auto &w : walls) {
            grid[w[0]][w[1]] = 1;
        }
        for(auto &g : guards) {
            grid[g[0]][g[1]] = 2;
        }
        vector<vector<int>>dir = {{0,-1},{-1,0},{0,1},{1,0}};
        for(auto &g : guards) {
            int r = g[0];
            int c = g[1];
            for(auto &d : dir) {
                int nr = r + d[0];
                int nc = c + d[1];
                while(nr >= 0 && nc >= 0 && nr < m && nc < n && grid[nr][nc] != 1 && grid[nr][nc] != 2) {
                    if(grid[nr][nc] == 0) {
                        grid[nr][nc] = 3;
                    }
                    nr += d[0];
                    nc += d[1];
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    ans++;
                }
            }
        }
        return ans;
    }
};