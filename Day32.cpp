// Leetcode 2929. Distribute Candies Among Children II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long distributeCandies(int n, int limit) {
        //for child 1
        int minCh1 = max(0,n-2*limit);
        int maxCh1 = min(n,limit);
        long long count = 0;
        for(int i = minCh1;i<=maxCh1;i++) {
            int N = n-i;
            int minCh2 = max(0,N-limit);
            int maxCh2 = min(N,limit);
            count += (maxCh2-minCh2+1);
        }
        return count;
    }
};