/*
 * @lc app=leetcode id=203 lang=cpp
 *
 * [203] Remove Linked List Elements
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
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummyHead(INT_MIN, head);
        ListNode* prev = &dummyHead;
        while (prev->next) {
            if (prev->next->val == val) {
                ListNode* temp = prev->next;
                prev->next = temp->next;
                delete(temp);
            } else prev = prev->next;
        }
        return dummyHead.next;
    }
};
// @lc code=end

