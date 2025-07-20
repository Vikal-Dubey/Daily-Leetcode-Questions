// Leetcode 2040. Kth Smallest Product of Two Sorted Arrays
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long findCountSmallest(vector<int>& nums1,vector<int>& nums2,long long midProduct) {
        long long productCount = 0;
        int n = nums2.size();
        for(int i = 0; i < nums1.size(); i++) {
            if(nums1[i] >= 0) {
                int l = 0;
                int r = n-1;
                int m = -1; //invalid Index on the left side
                while(l <= r) {
                    int mid = l + (r-l)/2;
                    
                    long long product = 1LL * nums1[i] * nums2[mid];
                    if(product <= midProduct) {
                        m = mid;
                        l = mid + 1;
                    } else {
                        r = mid-1;
                    }
                }
                productCount += (m+1);  //covered by nums[i]
            } else {
                //product will be negative and right hand side will contain negative products and left hand size smaller 
                int l = 0;
                int r = n-1;
                int m = n;//invalid index on the right
                
                while(l <= r) {
                    int mid = l + (r-l)/2;

                    long long product = 1LL * nums1[i] * nums2[mid];
                    if(product <= midProduct) {
                        m = mid;
                        r = mid-1;
                    } else {
                        l = mid+1;
                    }
                }
                productCount += (n - m);
            }
        }
        return productCount;
    }
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long result = 0;

        long long l = -1e10;//minProduct Possible
        long long r = 1e10; //maxProuct Possible
        while(l <= r) {
            long long midProduct = l + (r-l)/2;
            //checking if this is the kth smallest or not

            long long countSmallest = findCountSmallest(nums1,nums2,midProduct);

            if(countSmallest >= k) {
                result = midProduct;
                r = midProduct - 1;
            } else {
                l = midProduct + 1;
            }
        }
        return result;
    }
};