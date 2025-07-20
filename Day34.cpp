// Leetcode 1298. Maximum Candies You Can Get from Boxes
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int collectedCandies = 0;//TC : O(n)    SC : O(n)
        unordered_set<int>visited;
        unordered_set<int>foundBoxes;
        queue<int>q;
        for(int box:initialBoxes) {
            foundBoxes.insert(box);
            if(status[box] == 1) {
                q.push(box);
                visited.insert(box);
                collectedCandies += candies[box];
            }
        }
        while(!q.empty()) {
            int box = q.front();
            q.pop();
            for(int insideBox:containedBoxes[box]) {
                foundBoxes.insert(insideBox);
                if(status[insideBox] == 1 && !visited.count(insideBox)) {
                    q.push(insideBox);
                    visited.insert(insideBox);
                    collectedCandies += candies[insideBox];
                }
            }
            for(int boxKey : keys[box]) {
                status[boxKey] = 1;
                if(foundBoxes.count(boxKey) && !visited.count(boxKey)) {
                    q.push(boxKey);
                    visited.insert(boxKey);
                    collectedCandies += candies[boxKey];
                }
            }
        }
        return collectedCandies;
    }
};