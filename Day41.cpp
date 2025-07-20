// Leetcode 3442. Maximum Difference Between Even and Odd Frequency I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDifference(string s) {
        int n = s.size();
        unordered_map<char,int>mp;
        for(auto ch:s) {
            mp[ch]++;
        }
        int maxOdd = 1,minEven = n;
        for(auto ele:mp) {
            if(ele.second % 2 != 0) {
                maxOdd = max(maxOdd,ele.second);
            } else {
                minEven = min(minEven,ele.second);
            }
        }
        return maxOdd-minEven; 
    }
};