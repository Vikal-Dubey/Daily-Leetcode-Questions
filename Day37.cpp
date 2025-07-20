// Leetcode 2434. Using a Robot to Print the Lexicographically Smallest String
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char>minCharToRt(n);
        minCharToRt[n-1] = s[n-1];
        for(int i = n-2;i>=0;i--) {
            minCharToRt[i] = min(minCharToRt[i+1],s[i]);
        }
        string paper = "",t = "";
        int i = 0;
        while(i<n) {
            t.push_back(s[i]);
            char minChar = (i+1<n)?(minCharToRt[i+1]):s[i];
            while(!t.empty() && t.back() <= minChar) {
                paper += t.back();
                t.pop_back();
            }
            i++;
        }
        while(!t.empty()) {
            paper += t.back();
            t.pop_back();
        }
        return paper;
    }
};