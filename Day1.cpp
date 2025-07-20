// Leetcode 2071. Maximum Number of Tasks You Can Assign
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& tasks, vector<int>& workers, int pills, int strength,int mid) {
        int pillsUsed = 0;
        multiset<int> st(workers.begin(),workers.begin() + mid);
        for(int i = mid - 1; i >= 0; i--) {
            int reqrd = tasks[i];
            auto it = prev(st.end());
            if(*it >= reqrd) {
                st.erase(it);
            } else if(pillsUsed >= pills) {
                return false;
            } else {
                auto weakestWorkerIt = st.lower_bound(reqrd - strength);
                if(weakestWorkerIt == st.end()) {
                    return false;
                }
                st.erase(weakestWorkerIt);
                pillsUsed++;
            }
        }
        return true;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        int m = tasks.size();
        int n = workers.size();
        int l = 0;
        int r = min(m,n);
        sort(tasks.begin(),tasks.end());
        sort(workers.begin(),workers.end(),greater<int>());
        int result = 0;
        while(l <= r) {
            int mid = l + (r-l)/2;
            if(check(tasks,workers,pills,strength,mid)) {
                result = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return result;
    }
};