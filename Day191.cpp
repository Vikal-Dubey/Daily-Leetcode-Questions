#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(long long& mid,vector<long long> diff, int r, int k) {
        int n = diff.size();
        long long cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];
            if(cumSum < mid) {
                long long need = mid - cumSum;
                if(need > k) {
                    return false;
                } else {
                    cumSum += need;
                    k -= need;
                    if(i+2*r+1 < n) {
                        diff[i+2*r+1] -= need;
                    }
                }
            }
        }
        return true;
    }
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long>diff(n,0);
        for(int i = 0; i < n; i++) {
            int j = max(0,i-r);
            diff[j] += stations[i];
            if(i+r+1 < n) {
                diff[i+r+1] -=  stations[i];
            }
        }
        long long lo = *min_element(stations.begin(),stations.end());
        long long hi = accumulate(stations.begin(),stations.end(),0LL) + k;
        long long ans = 0;
        while(lo <= hi) {
            long long mid = lo + (hi-lo)/2;
            if(check(mid,diff,r,k)) {
                lo = mid + 1;
                ans = mid;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }
};