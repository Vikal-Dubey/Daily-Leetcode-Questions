// Leetcode 2138. Divide a String Into Groups of Size k
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        string str;
        int i = 0;
        while(i<s.size()) {
            int j = i + k - 1;
            str = s.substr(i,j-i+1);
            ans.push_back(str);
            i += k;
        }
        int x = ans.size() - 1;
        if(ans[x].size() != k) {
            for(int i = 0;i<k;i++) {
                ans[x] += fill;
                if(ans[x].size() == k) break;
            }
        }
        return ans;
    }
};