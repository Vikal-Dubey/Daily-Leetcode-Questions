// Leetcode 2131. Longest Palindrome by Concatenating Two Letter Words
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>mp;
        int ans = 0;
        for(auto s : words) {
            string reversedS = s;
            swap(reversedS[0],reversedS[1]);
            if(mp[reversedS]>0) {
                ans+=4;
                mp[reversedS]--;
            } else {
                mp[s]++;
            }
        }
        for(auto ele:mp) {
            string s = ele.first;
            int freq = ele.second;
            if(s[0] == s[1] && freq>0) {
                ans += 2;
                break;
            }
        }
        return ans;
    }
};