// Leetcode 386. Lexicographical Numbers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int n,vector<int>& ans,int x) {
        if(x>n) return;
        ans.push_back(x);
        for(int i = 0;i<10;i++) {
            int temp = x*10+i;
            if(temp>n)  return;
            solve(n,ans,temp);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1;i<=9;i++) {
            solve(n,ans,i);
        }
        return ans;
    }
};