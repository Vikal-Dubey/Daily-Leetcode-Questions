// Leetcode 3024. Type of Triangle
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int a = nums[0],b = nums[1],c = nums[2];
        bool isTriangle = (a+b>c && b+c>a && a+c>b);
        if(isTriangle) {
            if(a == b && b == c)  return "equilateral";
            if((a == b && b!=c) || (b == c && b!=a) || (a == c && b!=c) )   return "isosceles";
            else return "scalene";
        } else  return "none";
    }
};