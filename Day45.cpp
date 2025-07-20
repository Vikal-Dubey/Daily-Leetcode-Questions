// Leetcode 2616. Minimize the Maximum Difference of Pairs
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        string minAns = "",maxAns = "";
        char ele;
        int n = s.size();
        for(int i = 0;i<n;i++) {
            if(s[i] != '9') {
                ele = s[i];
                break;
            }
        }
        for(int i = 0;i<n;i++) {
            if(s[i] == ele) maxAns += '9';
            else {
                maxAns += s[i];
            }
        }
        for(int i = 0;i<n;i++) {
            if(s[i] == s[0]) minAns += '0';
            else {
                minAns += s[i];
            }
        }
        return stoi(maxAns) - stoi(minAns);
    }
};