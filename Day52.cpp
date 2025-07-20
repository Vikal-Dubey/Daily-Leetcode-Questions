// Leetcode 3085. Minimum Deletions to Make String K-Special
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int>freq(26,0);
        int n = word.size();

        for(int i = 0;i<n;i++) {
            freq[word[i] - 'a']++;
        }
        sort(freq.begin(),freq.end());


        int ans = INT_MAX;
        int cumulativeDel = 0;
        for(int i = 0;i<26;i++) {
            
            int del = cumulativeDel;

            for(int j = 25;j>i;j--) {
                
                if(freq[j]-freq[i] <= k) {
                    break;
                }

                del += freq[j] - freq[i] - k;
            }
            ans = min(ans,del);
            cumulativeDel += freq[i];
        }
        return ans;
    }
};