// Leetcode 2081. Sum of k-Mirror Numbers
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string findBaseK(long long num,int k) {
        if(num == 0) 
            return "0";
        string res = "";
        while(num) {
            res += to_string(num % k);
            num = num / k;
        }
        return res;
    }
    bool isPalindrome(string basek) {
        int i = 0,j = basek.size()-1;
        while(i <= j) {
            if(basek[i] != basek[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    long long kMirror(int k, int n) {
        long long sum = 0;
        int L = 1;  //create L lenth palindromes

        while(n>0) {
            int half_length = (L+1)/2;

            long long min_num = pow(10,half_length-1);
            long long max_num = pow(10,half_length)-1;
            
            for(int num = min_num; num <= max_num; num++) {

                string first_half = to_string(num);
                string second_half = first_half;
                reverse(second_half.begin(),second_half.end());

                string pal = "";
                if(L%2 == 0) {
                    pal = first_half + second_half;
                } else {
                    pal = first_half + second_half.substr(1);
                }

                long long num_pal = stoll(pal);

                string baseK = findBaseK(num_pal,k);

                if(isPalindrome(baseK)) {
                    sum += num_pal;
                    n--;
                    if(n == 0)
                        break;
                }
            }
            L++;
        }
        return sum;
    }
};