/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head(-1);
        ListNode *prev = &head;
        int carry = 0;
        while (l1 || l2) {
            int value = carry;
            if (l1 != nullptr) {
                value += l1->val;    
                l1 = l1->next;
            }
            if (l2 != nullptr) {
                value += l2->val;
                l2 = l2->next;
            } 
 
            carry = value / 10;
            value %= 10;

            prev->next = new ListNode(value);
            prev = prev->next;
        }
        if (carry > 0) {
            prev->next = new ListNode(carry);        
        }
        return head.next;
    }
};
// @lc code=end
