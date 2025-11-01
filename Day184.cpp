#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>ans;
        for(auto &it : nums) {
            if(st.count(it)) {
                ans.push_back(it);
                continue;
            }
            st.insert(it);
        }
        return ans;
    }
};