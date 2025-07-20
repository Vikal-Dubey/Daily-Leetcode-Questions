// Leetcode 2894. Divisible and Non-divisible Sums Difference
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int differenceOfSums(int n, int m) {
        int n1 = 0,n2 = 0;
        for(int i = 1;i<=n;i++) {
            if(i%m == 0)    n2 += i;
            else n1 += i;
        }
        return n1-n2;
    }
};