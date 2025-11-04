#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int>ans;
        int n = nums.size();
        for(int i = 0; i <= n-k; i++) {
            vector<int>mp(52,0);
            int sum = 0;
            for(int j = i; j < i+k; j++) {
                sum += nums[j];
                mp[nums[j]]++;
            }
            priority_queue<pair<int,int>>pq;
            for(int i = 1; i <= 51; i++) {
                if(mp[i] != 0) {
                    pq.push({mp[i],i});
                }
            }
            if(pq.size() < x) {
                ans.push_back(sum);
            } else {
                int a = 0;
                int temp = 0;
                while(a < x) {
                    temp += pq.top().first * pq.top().second;
                    pq.pop();
                    a++;
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};