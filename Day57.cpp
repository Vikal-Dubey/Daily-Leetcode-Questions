// Leetcode 2311. Longest Binary Subsequence Less Than or Equal to K
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
        int length = 0;
        long long powerValue = 1;//2^0

        for(int i = n-1; i >= 0; i--) {
            if(s[i] == '0')
                length++;
            else if(powerValue <= k) {
                k -= powerValue;
                length++;
            }
            if(powerValue <= k) {
                powerValue <<= 1;//(powerValue * 2)
            }
        }
        return length;
    }
};