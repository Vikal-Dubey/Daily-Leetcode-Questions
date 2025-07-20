// Leetcode 3343. Count Number of Balanced Permutations
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int n;
    int totalDigitSum;
    const int M = 1e9 + 7;

    long long findPower(long long a, long long b) {
        long long res = 1;
        a %= M;
        while (b > 0) {
            if (b % 2 == 1)
                res = (res * a) % M;
            a = (a * a) % M;
            b /= 2;
        }
        return res;
    }

    long long solve(int digit, int evenCount, int evenSum,
                    vector<int>& freq, vector<long long>& invFact,
                    vector<vector<vector<long long>>>& dp) {
        if (digit == 10) {
            if (evenSum * 2 != totalDigitSum || evenCount != (n + 1) / 2) return 0;
            return 1;
        }

        if (dp[digit][evenCount][evenSum] != -1) return dp[digit][evenCount][evenSum];

        long long ways = 0;
        for (int cnt = 0; cnt <= freq[digit]; ++cnt) {
            int even = cnt;
            int odd = freq[digit] - cnt;

            if (evenCount + even > (n + 1) / 2) continue;
            if (evenSum + digit * even > totalDigitSum / 2) continue;

            long long next = solve(digit + 1, evenCount + even, evenSum + digit * even, freq, invFact, dp);
            long long div = (invFact[even] * invFact[odd]) % M;
            ways = (ways + (next * div) % M) % M;
        }
        return dp[digit][evenCount][evenSum] = ways;
    }

    int countBalancedPermutations(string velunexorai) {
        n = velunexorai.size();
        totalDigitSum = 0;
        vector<int> freq(10, 0);
        for (char c : velunexorai) {
            totalDigitSum += c - '0';
            freq[c - '0']++;
        }

        if (totalDigitSum % 2 != 0) return 0;

        // Compute factorials and inverse factorials
        vector<long long> fact(n + 1, 1), invFact(n + 1, 1);
        for (int i = 1; i <= n; ++i) fact[i] = (fact[i - 1] * i) % M;
        for (int i = 0; i <= n; ++i) invFact[i] = findPower(fact[i], M - 2);

        // Compute total permutations of even and odd index positions
        long long totalPerm = (fact[(n + 1) / 2] * fact[n / 2]) % M;

        // DP memoization: digit, evenCount, evenSum
        vector<vector<vector<long long>>> dp(10,
            vector<vector<long long>>((n + 1) / 2 + 1,
            vector<long long>(totalDigitSum / 2 + 1, -1)));

        long long validAssignments = solve(0, 0, 0, freq, invFact, dp);
        return (validAssignments * totalPerm) % M;
    }
};
