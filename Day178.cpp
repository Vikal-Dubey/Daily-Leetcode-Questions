#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalMoney(int n) {
        int mon = 1;
        int total = 0;
        int dayAmt = mon;
        for(int i = 1; i <= n; i++) {
            total += dayAmt;
            dayAmt++;
            if(i % 7 == 0) {
                mon++;
                dayAmt = mon;
            }
        }
        return total;
    }
};