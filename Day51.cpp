// Leetcode 3443. Maximum Manhattan Distance After K Changes
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDistance(string s, int k) {
        int north = 0;
        int south = 0;
        int west = 0;
        int east = 0;
        int maxDis = 0;
        for(int i = 0;i<s.size();i++) {
            if(s[i] == 'N') north++;
            else if(s[i] == 'S') south++;
            else if(s[i] == 'E') east++;
            else if(s[i] == 'W') west++;

            int currMaxDis = abs(north - south) + abs(east - west);
            int steps = i+1;
            int wasted = steps - currMaxDis;
            
            int extra = 0;
            if(wasted != 0) {
                extra = min(wasted,2*k);
            }
            int finalMaxCount = currMaxDis + extra;
            maxDis = max(finalMaxCount,maxDis);
        }
        return maxDis;
    }
};