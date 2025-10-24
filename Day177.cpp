#include<bits/stdc++.h>
using namespace std;

// Brute force to find the next beautiful number 
class Solution {
public:
    bool balanced(int num) {
        vector<int>freq(10,0);
        while(num) {
            freq[num%10]++;
            num /= 10;
        }
        for(int i = 0; i < 10; i++) {
            if(i != freq[i] && freq[i] != 0) {
                return false;
            }
        }
        return true;
    }
    int nextBeautifulNumber(int n) {
        for(int num = n+1; num <= 1e8; num++) {
            if(balanced(num)) {
                return num;
            }
        }
        return -1;
    }
};

// By backtracking
class Solution {
public:
    vector<int>digitsCount{0,1,2,3,4,5,6,7,8,9};
    int backtrack(int n,int curr,int count) {
        if(count == 0) {
            for(int digit = 1; digit <= 9; digit++) {
                if(digitsCount[digit] > 0 && digitsCount[digit] != digit) {
                    return 0;
                }
            }
            return curr > n ? curr : 0;
        }
        int result = 0;
        for(int digit = 1; digit <= 9; digit++) {
            if(digitsCount[digit] > 0 && digitsCount[digit] <= count) {
                digitsCount[digit]--;
                result = backtrack(n,curr*10+digit,count-1);
                if(result)  return result;
                digitsCount[digit]++;
            }
        }
        return result;
    }
    int nextBeautifulNumber(int n) {
        int numDigits = to_string(n).size();
        int result = backtrack(n,0,numDigits);
        if(result == 0) {
            result = backtrack(n,0,numDigits+1);
        }
        return result;
    }
};

