// Leetcode 1498. Number of Subsequences That Satisfy the Given Sum Condition
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int M = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        long long result = 0;
        int n = nums.size();
        int l = 0,r = n - 1;
        sort(nums.begin(),nums.end());

        vector<long long>power(n,1);
        for(int i = 1;i < n;i++) {
            power[i] = (power[i-1] * 2) % M;
        }

        while(l <= r) {
            if(nums[l] + nums[r] <= target) {
                int diff = r - l;
                result = (result + power[diff]);
                l++;
            } else {
                r--;
            }
        }
        return result % M;
    }
};