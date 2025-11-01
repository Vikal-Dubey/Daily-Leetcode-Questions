#include<bits/stdc++.h>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>st;
        for(auto &x : nums) {
            st.insert(x);
        }
        ListNode* dummy = new ListNode(10);
        ListNode* temp = dummy;
        while(head) {
            if(!st.count(head->val)) {
                temp -> next = head;
                temp = temp -> next;
            }
            head = head -> next;
        }
        temp -> next = NULL;
        return dummy->next;
    }
};