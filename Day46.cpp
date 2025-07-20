// Leetcode 1432. Max Difference You Can Get From Changing an Integer
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDiff(int num) {
        string maxNum = "";
        string minNum = "";
        string str = to_string(num);
        char ch = '\0';
        for (int i = 0; i < str.size(); i++) {
            if (str[i] != '9') {
                ch = str[i];
                break;
            }
        }

        if (ch == '\0') {
            // All digits are 9, nothing to change
            maxNum = str;
        } else {
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == ch)
                    maxNum += '9';
                else
                    maxNum += str[i];
            }
        }

        // Step 2: Build minNum
        if (str[0] != '1') {
            // If first digit is not 1, replace all of it with 1
            char ch2 = str[0];
            for (int i = 0; i < str.size(); i++) {
                if (str[i] == ch2)
                    minNum += '1';
                else
                    minNum += str[i];
            }
        } else {
            // First digit is 1, look for a digit (not 0 or 1) from i = 1
            char ch2 = '\0';
            for (int i = 1; i < str.size(); i++) {
                if (str[i] != '0' && str[i] != '1') {
                    ch2 = str[i];
                    break;
                }
            }

            if (ch2 == '\0') {
                // No replacement needed
                minNum = str;
            } else {
                for (int i = 0; i < str.size(); i++) {
                    if (str[i] == ch2)
                        minNum += '0';
                    else
                        minNum += str[i];
                }
            }
        }
        return stoi(maxNum) - stoi(minNum);
    }
};