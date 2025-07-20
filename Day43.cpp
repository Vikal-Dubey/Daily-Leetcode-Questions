// Leetcode 3423. Maximum Difference Between Adjacent Elements in a Circular Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int maxDiff = INT_MIN;
        int n = nums.size();
        for(int i = 1;i<n;i++) {
            if(i == n-1 && abs(nums[i] - nums[0])>maxDiff) maxDiff = abs(nums[i] - nums[0]);
            maxDiff = (abs(nums[i] - nums[i-1]) > maxDiff)?abs(nums[i] - nums[i-1]):maxDiff;
        }
        return maxDiff;
    }
};