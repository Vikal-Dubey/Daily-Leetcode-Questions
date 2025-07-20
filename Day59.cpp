// Leetcode 2099. Find Subsequence of Length K With the Largest Sum
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == n) {
            return nums;
        }

        vector<int>temp(nums);
        
        nth_element(begin(temp),begin(temp) + k - 1,end(temp),greater<int>());
        
        int kthLargest = temp[k-1];
        int countKthLargest = count(begin(temp),begin(temp) + k, kthLargest);
        vector<int>result;

        for(int i = 0; i < n; i++) {
            if(nums[i] > kthLargest) {
                result.push_back(nums[i]);
            }
            else if(nums[i] == kthLargest && countKthLargest) {
                result.push_back(nums[i]);
                countKthLargest--;
            }
            
            if(result.size() == k) {
                return result;
            }
        }
        return result;
    }
};