// Leetcode 2016. Maximum Difference Between Increasing Elements
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minDiff = -1;
        int prevMin = nums[0];
        for(int i = 1;i<nums.size();i++) {
            if(nums[i]>prevMin) {
                minDiff = max(minDiff,nums[i]-prevMin);
            } else {
                prevMin = nums[i];
            }
        }
        return minDiff;
    }
};