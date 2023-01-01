#include <iostream>
using namespace std;
/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start

//Definition for singly-linked laist.

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l_sum;
        l_sum = new ListNode;
        ListNode* l_result = l_sum;

        int carry = 0, sum = 0;
        while(l1 || l2){
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            l_sum->val = sum % 10;
            carry = sum / 10;

            if((l1 && l1->next) || (l2 && l2->next) || carry){
                l_sum->next = new ListNode;
                l_sum = l_sum->next;
            }

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(carry) l_sum->val = carry;
        return l_result;
    }
};

int main(){
    Solution solution;
    ListNode* l1;
    l1 = new ListNode;
    l1->next = new ListNode;
    l1->next->next = new ListNode;

    l1->val = 3;
    l1->next->val = 4;
    l1->next->next->val = 2;


    ListNode* l2;
    l2 = new ListNode;
    l2->next = new ListNode;
    l2->next->next = new ListNode;

    l2->val = 4;
    l2->next->val = 6;
    l2->next->next->val = 5;


    ListNode* sum = solution.addTwoNumbers(l1, l2);
    while(sum){
        cout << sum->val << endl;
        sum = sum->next;
    }
    return 0;
}
// @lc code=end

