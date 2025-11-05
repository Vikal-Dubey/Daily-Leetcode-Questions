#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    set<pair<int,int>>main;
    set<pair<int,int>>sec;

    void insertInSet(const pair<int,int>& p,long long &sum,int &x) {
        if(main.size() < x || p > *main.begin()) {
            sum += 1LL * p.first * p.second;
            main.insert(p);
            if(main.size() > x) {
                auto smallest = *main.begin();
                sum -= 1LL * smallest.first * smallest.second;
                main.erase(smallest);
                sec.insert(smallest);
            }
        } else {
            sec.insert(p);
        }
    }
    void removeFromSet(const pair<int,int>&p, long long &sum,int &x) {
        if(main.count(p)) {
            sum -= 1LL * p.first * p.second;
            main.erase(p);
            if(sec.size() != 0) {
                auto largest = *sec.rbegin();
                sum += 1LL * largest.first * largest.second;
                sec.erase(largest);
                main.insert(largest);
            }
        } else {
            sec.erase(p);
        }
    }
    vector<long long> findXSum(vector<int>& nums, int k, int x) {
        long long sum = 0;
        int n = nums.size();
        unordered_map<int,int>mp;
        vector<long long>result;
        int i = 0, j = 0;
        while(j < n) {
            if(mp[nums[j]] > 0) {
                removeFromSet({mp[nums[j]] , nums[j]},sum,x);
            }
            mp[nums[j]]++;
            insertInSet({mp[nums[j]] , nums[j]},sum,x);
            if(j - i + 1 == k) {
                result.push_back(sum);
                removeFromSet({mp[nums[i]],nums[i]},sum,x);
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                } else {
                    insertInSet({mp[nums[i]] , nums[i]},sum,x);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};