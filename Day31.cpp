// Leetcode 909. Snakes and Ladders
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    pair<int,int> getCoOrd(int n,int x) {
        int r = (n-1)-(x-1)/n;
        int c = (x-1)%n;
        if(r%2 == n%2) {
            c = (n-1)-c;
        }
        return {r,c};
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<int>q;
        int n = board.size();
        vector<vector<bool>>visited(n,vector<bool>(n,false));
        q.push(1);
        visited[n-1][0] = true;
        int steps = 0;
        while(!q.empty()) {
            int N = q.size();
            while(N--) {
                int x = q.front();
                q.pop();
                if(x == n*n)    return steps;
                for(int i = 1;i<=6;i++) {
                    if(x+i>n*n) break;
                    int val = x+i;
                    pair<int,int> coOrd = getCoOrd(n,val);
                    int row = coOrd.first,col = coOrd.second;
                    if(visited[row][col] == true)   continue;
                    visited[row][col] = true;
                    if(board[row][col] == -1) {
                        q.push(val);
                    }else {
                        q.push(board[row][col]);
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};