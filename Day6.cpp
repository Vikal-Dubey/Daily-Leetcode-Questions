// Leetcode 1920. Build Array from Permutation
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i = 0;i<n;i++) {
            ans[i] = nums[nums[i]];
        }
        return ans;
    }
};