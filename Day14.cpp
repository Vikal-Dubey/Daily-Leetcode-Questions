// Leetcode 3337. Total Characters in String After Transformations II
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    typedef vector<vector<int>>Matrix;
    int M = 1e9+7;
    Matrix matrixMulti(Matrix& a,Matrix& b) {
        Matrix C(26,vector<int>(26,0));
        for(int i = 0;i<26;i++) {
            for(int j = 0;j<26;j++) {
                for(int k = 0;k<26;k++) {
                    C[i][j] =( C[i][j] + (1LL*a[i][k] * b[k][j] % M)) % M;
                }
            }
        }
        return C;
    }
    Matrix matrixExponentiation(Matrix& base,int exponent) {
        if(exponent == 0) {
            Matrix I(26,vector<int>(26,0));
            for(int i = 0;i<26;i++) {
                I[i][i] = 1;
            }
            return I;
        }
        Matrix half = matrixExponentiation(base,exponent/2);
        Matrix result = matrixMulti(half,half);
        if(exponent%2 == 1) result = matrixMulti(result,base);
        return result;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        //Final freq state =  T^t * initial freq State
        vector<int>initialfreq(26,0);
        for(auto ch:s) {
            initialfreq[ch-'a']++;
        } 
        //Now form T matrix
        Matrix T(26,vector<int>(26,0));
        for(int i = 0;i<26;i++) {
            for(int add = 1;add<=nums[i];add++) {
                T[(i+add)%26][i]++;
            }
        }
        //Find T^t
        Matrix Tt = matrixExponentiation(T,t);
        vector<int>finalFreq(26,0);
        for(int i = 0;i<26;i++) {
            for(int j = 0;j<26;j++) {
                finalFreq[i] = (finalFreq[i] + (1LL * Tt[i][j] * initialfreq[j]) % M) % M;  
            }
        }
        int resultLength = 0;
        for(int i = 0;i<26;i++) {
            resultLength = (resultLength + finalFreq[i])%M;
        }
        return resultLength;
    }
};