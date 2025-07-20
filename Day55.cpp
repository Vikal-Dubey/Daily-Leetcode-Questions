// Leetcode 2200. Find All K-Distant Indices in an Array
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int>result;
        int n = nums.size();
        for(int j = 0; j<n; j++) {
            if(nums[j] == key) {
                int start = max(j - k,0);
                int end = min(j+k,n-1);
                if(!result.empty() && result.back() >= start) {
                    start = result.back() + 1;
                }
                for(int i = start; i <= end; i++) {
                    result.push_back(i);
                }
            }
        }
        return result;
    }
};