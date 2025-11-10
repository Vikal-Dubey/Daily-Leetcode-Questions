#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int>st;
        int oprs = 0;
        for(int &num : nums) {
            while(!st.empty() && st.top() > num) {
                st.pop();
            }
            if(st.empty() || st.top() < num) {
                st.push(num);
                if(num != 0)    oprs++;
            }
        }
        return oprs;
    }
};