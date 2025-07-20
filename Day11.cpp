// Leetcode 1550. Three Consecutive Odds
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int conseOdd = 0;
        if(arr.size()<3)    return false;
        for(int i = 0;i<arr.size();i++) {
            if(arr[i] % 2) conseOdd++;
            else    conseOdd = 0;
            if(conseOdd == 3)   return true;
        }
        return false;
    }
};