// Leetcode 73. Set Matrix Zeroes
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRowInfected = false;
        bool firstColInfected = false;
        for(int row = 0;row<matrix.size();row++) {
            if(matrix[row][0] == 0) firstColInfected = true;
        }
        for(int col = 0;col<matrix[0].size();col++) {
            if(matrix[0][col] == 0) firstRowInfected = true;
        }
        for(int i = 0;i<matrix.size();i++) {
            for(int j = 0;j<matrix[0].size();j++) {
                if(matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i = 1;i<matrix.size();i++) {
            for(int j = 1;j<matrix[0].size();j++) {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)   matrix[i][j] = 0;
            }
        }
        if(firstRowInfected) {
            for(int col = 0;col<matrix[0].size();col++) {
                matrix[0][col] = 0;
            }
        }
        if(firstColInfected) {
            for(int row = 0;row<matrix.size();row++) {
                matrix[row][0] = 0;
            }
        }
    }
};