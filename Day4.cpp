// Leetcode 1128. Number of Equivalent Domino Pairs
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<pair<int,int>, int>m;
        int count = 0;
        for(auto x:dominoes) {
            if(x[0]>x[1])   swap(x[0],x[1]);
            count += m[make_pair(x[0],x[1])]++;
        }
        return count;
    }
};