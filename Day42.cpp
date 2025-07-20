// Leetcode 3445. Maximum Difference Between Even and Odd Frequency II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getState(int count_a,int count_b) {
        int parity_a = count_a % 2;
        int parity_b = count_b % 2;

        if(parity_a == 0 && parity_b == 0)   return 0; //even even (0,0)
        if(parity_a == 0 && parity_b == 1)   return 1; //even odd (0,1)
        if(parity_a == 1 && parity_b == 0)   return 2; //odd even (1,0)
        return 3; //odd odd (1,1)
    }
    int maxDifference(string s, int k) {
        int n = s.size();
        int result = INT_MIN;

        // Step 1 : Try all possible pairs a and b from (0 to 4) where a != b
        for(char a = '0'; a <= '4' ; a++) {
            for(char b = '0'; b <= '4' ; b++) {

                if(a == b)  continue;

                // stateMinPrev[state] = stores the smallest value of the count of a - count of b
                vector<int>stateMinPrev(4,INT_MAX);
                
                // count of a and b till index r
                int count_a = 0,count_b = 0;

                //count of a and b till index l
                int prev_a = 0,prev_b = 0;

                //Start the sliding window
                int l = -1,r = 0;
                while(r<n) {
                    count_a += (s[r] == a) ? 1 : 0;
                    count_b += (s[r] == b) ? 1 : 0;

                    while(r - l >= k && count_b - prev_b >= 2 && count_a - prev_a >=1) {
                        int leftState = getState(prev_a ,prev_b);
                        stateMinPrev[leftState] = min(stateMinPrev[leftState],prev_a-prev_b);
                        l++;
                        prev_a += (s[l] == a) ? 1 : 0;
                        prev_b += (s[l] == b) ? 1 : 0;
                    }
                    int rightState = getState(count_a,count_b);
                    int bestLeftState = rightState^2;
                    int bestMinDiffValueLeft = stateMinPrev[bestLeftState];
                    if(bestMinDiffValueLeft != INT_MAX) {
                        result = max(result,(count_a-count_b) - bestMinDiffValueLeft);
                    }
                    r++;
                }
            }
        }
        return result;
    }
};