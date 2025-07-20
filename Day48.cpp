// Leetcode 3405. Count the Number of Arrays with K Matching Adjacent Elements
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
class Solution {
public:
    // Binomial Exponentiation
    int findPower(long long a,long long b) {
        if(b == 0)  return 1;
        long long half = findPower(a,b/2);
        long long result = (half * half) % MOD;
        
        if(b % 2 == 1)    result = (result * a) % MOD;
        return result;
    }
    long long nCr(int n,int r,vector<long long>& fact,vector<long long>& fermetFact) {
        return (fact[n] * fermetFact[n-r] % MOD * fermetFact[r] % MOD) % MOD;
    }
    int countGoodArrays(int n, int m, int k) {
        vector<long long>fact(n+1,1);
        fact[0] = 1;
        fact[1] = 1;
        for(int i = 2;i<=n;i++) {
            fact[i] = (fact[i-1] * i) % MOD;
        }
        //Inverse Factorial Precalculate : Fermet's Little Theorem
        vector<long long>fermetFact(n+1,1);
        for(int i = 0;i<=n;i++) {
            fermetFact[i] = findPower(fact[i],MOD-2);
        }
        long long result = nCr(n-1,k,fact,fermetFact);
        result = (result * m) % MOD;
        result = (result * findPower(m-1,n-k-1)) % MOD;
        return result;
    }
};