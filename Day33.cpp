// Leetcode 135. Candy
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int>L2R(n,1);//stores maximum number of candies from left to right
        vector<int>R2L(n,1);//stores maximum number of candies from right to left
        for(int i = 1;i<n;i++) {
            if(ratings[i]>ratings[i-1]) {
                L2R[i] = L2R[i-1]+1;
            }
        }
        for(int i = n-1;i>0;i--) {
            if(ratings[i-1]>ratings[i]) {
                R2L[i-1] = R2L[i]+1;
            }
        }
        int sum = 0;
        for(int i = 0;i<n;i++) {
            sum += max(L2R[i],R2L[i]);
        }
        return sum;
    }
};