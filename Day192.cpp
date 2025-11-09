#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumOneBitOperations(int n) {
        if(n == 0) {
            return 0;
        }
        vector<long long>F(31,0);
        F[0] = 1;
        for(int i = 1; i <= 30; i++) {
            F[i] = 2*F[i-1]+1;
        }
        vector<int>temp(31,0);
        for(int i = 0; i < 31; i++) {
            if((n >> i) & 1) {
                temp[i] = 1;
            }
        }
        int ans = 0;
        bool flag = true;
        for(int i = 30; i >= 0; i--) {
            if(temp[i]) {
                if(flag) {
                    ans += F[i];
                } else {
                    ans -= F[i];
                }
                flag = !flag;
            }
        }
        return ans;
    }
};