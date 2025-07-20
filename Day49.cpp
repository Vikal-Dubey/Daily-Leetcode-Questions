// Leetcode 2966. Divide Array Into Arrays With Max Difference
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>finalAns;
        int minVal = nums[0];
        vector<int>ans;
        ans.push_back(minVal);
        for(int i = 1;i<nums.size();i++) {
            if(ans.size() < 3) {
                if(nums[i]-minVal <= k) {
                    ans.push_back(nums[i]);
                } else return {};
            } else {
                finalAns.push_back(ans);
                ans.clear();
                ans.push_back(nums[i]);
                minVal = nums[i];
            }
        }
        finalAns.push_back(ans);
        return finalAns;
    }
};