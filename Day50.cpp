// Leetcode 2294. Partition Array Such That Maximum Difference Is K
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int minVal = nums[0];
        int ans = 1;
        for(int i = 0;i<nums.size();i++) {
            if(nums[i]-minVal > k) {
                minVal = nums[i];
                ans++;
            }
        }
        return ans;
    }
};