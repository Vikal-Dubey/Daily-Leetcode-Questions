#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        int minOprs = 0;
        int curr = 0,prev = 0;
        for(int i = 0; i < target.size(); i++) {
            curr = target[i];
            if((curr > 0 && prev < 0) || (curr < 0 && prev > 0)) {
                minOprs += abs(curr);
            } else if(curr > prev) {
                minOprs += abs(curr - prev);
            }
            prev = curr;
        }
        return minOprs;
    }
};