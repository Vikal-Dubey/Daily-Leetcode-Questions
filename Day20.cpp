// Leetcode 3355. Zero Array Transformation I
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        //step 1 : Make difference array using queries
        vector<int>diff(n,0);
        for(auto query:queries) {
            int start = query[0];
            int end = query[1];
            int x = 1;
            diff[start] += x;
            if(end+1<n) {
                diff[end+1] -= x;
            }
        }
        //step 2 : Find cumulative effect on each index
        vector<int>result(n,0);
        int currSum = 0;
        for(int i = 0;i<n;i++) {
            currSum += diff[i];
            result[i] = currSum;
        }
        for(int i = 0;i<n;i++) {
            if(result[i]<nums[i]) { //nums[i] won't ever be 0
                return false;
            }
        }
        return true;
    }
};  