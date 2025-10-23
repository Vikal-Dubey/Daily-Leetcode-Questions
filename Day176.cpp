#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasSameDigits(string s) {
        int i = 0;
        string str = "";
        while(s.size() > 2 && i < s.size()-1) {
            str += (s[i] + s[i+1]) % 10;
            i++;
            if(i == s.size()-1) {
                s = str;
                i = 0;
                str = "";
            }
        }
        return s.size() == 2 && s[0] == s[1];
    }
};