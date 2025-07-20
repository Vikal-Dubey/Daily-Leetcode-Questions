// Leetcode 3170. Lexicographically Minimum String After Removing Stars
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef pair<char,int>p;
    struct comp{
        bool operator()(p& p1,p& p2) {
            if(p1.first == p2.first) {
                return p1.second<p2.second;
            }
            return p1.first>p2.first;
        }
    };
    string clearStars(string s) {
        priority_queue<p,vector<p>,comp>minEle;
        int n = s.size();
        for(int i = 0;i<n;i++) {
            if(s[i]!='*')   minEle.push({s[i],i});
            else {
                char x = minEle.top().first;
                int idx = minEle.top().second;
                minEle.pop();
                s[idx] = '*';
            }
        }
        string ans = "";
        for(int i = 0;i<n;i++) {
            if(s[i] != '*') ans += s[i];
        }
        return ans;
    }
};