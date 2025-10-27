#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0;
        int prev = 0;
        for(auto &row : bank) {
            int device = count(row.begin(),row.end(),'1');
            if(device > 0) {
                ans += prev * device;
                prev = device;
            }
        }
        return ans;
    }
};