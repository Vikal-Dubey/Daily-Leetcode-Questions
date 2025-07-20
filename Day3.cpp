// Leetcode 1007. Minimum Domino Rotations For Equal Row
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMinSteps(vector<int>& tops,vector<int>& bottoms,int val) {
        int topSteps = 0;
        int bottomSteps = 0;
        for(int i = 0; i < tops.size(); i++) {
            if(tops[i] != val && bottoms[i] != val) {
                return -1;
            } else if(tops[i] != val) {
                topSteps++;
            } else if(bottoms[i] != val) {
                bottomSteps++;
            }
        }
        return min(topSteps,bottomSteps);
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int result = INT_MAX;
        for(int val = 1; val <= 6; val++) {
            int steps = findMinSteps(tops,bottoms,val);
            if(steps != -1) {
                result = min(result,steps);
            }
        }
        return (result == INT_MAX) ? -1 : result;
    }
};