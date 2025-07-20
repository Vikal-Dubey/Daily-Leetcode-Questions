// Leetcode 3403. Find the Lexicographically Largest String From the Box I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends == 1)  return word;
        int n = word.size();
        string ans = "";
        int ansLnth = n-numFriends+1;
        for(int i = 0;i<n;i++) {
            int canTakeLnth = min(ansLnth,n-i);
            ans = max(ans,word.substr(i,canTakeLnth));
        }
        return ans;
    }
};