// Leetcode 440. K-th Smallest in Lexicographical Order
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int Count(long curr,long next,int n) {
        int countNum = 0;
        while(curr<=n) {
            countNum += (next-curr);
            curr *= 10;
            next *= 10;
            next = min(next,long(n+1));
        }  
        return countNum;
    }
    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;    //since we start from the first number we need k-1 more numbers;

        while(k>0) {
            int count = Count(curr,curr+1,n);
            if(count<=k) {
                k -= count;
                curr++;
            } else {
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
};