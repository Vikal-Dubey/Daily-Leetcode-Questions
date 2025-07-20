// Leetcode 2014. Longest Subsequence Repeated k Times
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSubsequence(string& s,string& sub,int k) {
        int i = 0,j = 0;
        int n = s.size();
        int L = sub.size();

        while(i<n && j< k*L) {
            if(s[i] == sub[j % L])
                j++;
            
            i++;
        }

        return j == k*L;
    }
    bool backtracking(string s,int k,vector<bool>& canUse,vector<int>& requiredFreq,string curr,string& result,int maxLen) {
        if(curr.size() == maxLen) {
            if( isSubsequence(s,curr,k) ) {
                result = curr;
                return true;
            }
            return false;
        }
        //Backtracing call
        for(int i = 25; i >= 00; i--) {
            if(canUse[i] == false || requiredFreq[i] == 0) {
                continue;
            }
            //DO
            char ch = i + 'a';
            curr.push_back(ch);
            requiredFreq[i]--;

            //EXPLORE
            if( backtracking(s,k,canUse,requiredFreq,curr,result,maxLen) ) {
                return true;
            }

            //UNDO
            curr.pop_back();
            requiredFreq[i]++;
        }

        return false;
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        int n = s.size();
        vector<int>freq(26,0);
        for(char ch : s) {
            freq[ch - 'a']++;
        }

        vector<bool>canUse(26,false);
        vector<int>requiredFreq(26,0);

        for(int i = 0; i < 26; i++) {
            if(freq[i] >= k) {
                canUse[i] = true;
                requiredFreq[i] = freq[i]/k;   //atmost this freq can be used in a subsequence
            }
        }

        int maxLen = n/k;

        string curr = "";
        string result = "";

        for(int len = maxLen; len >= 0; len--) {
            vector<int>tempRequiredFreq = requiredFreq;
            string curr = "";
            if( backtracking(s,k,canUse,tempRequiredFreq,curr,result,len) )
                return result;
        }

        return result;
    }
};