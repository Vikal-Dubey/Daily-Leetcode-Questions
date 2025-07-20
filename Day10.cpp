// Leetcode 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0,zero1 = 0;
        long long sum2 = 0,zero2 = 0;
        for(auto i : nums1) {
            sum1 += i;
            if(i == 0) {
                zero1++;
                sum1++;
            }
        }
        for(auto i : nums2) {
            sum2 += i;
            if(i == 0) {
                zero2++;
                sum2++;
            }
        }
        if(!zero1 && sum2>sum1 || !zero2 && sum1>sum2)  return -1;
        return max(sum1,sum2);
    }
};