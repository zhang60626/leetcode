/*
 * @lc app=leetcode id=83 lang=cpp
 *
 * [83] Remove Duplicates from Sorted List
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
    // compare value of current node with next one's
    // if true, delete next node.
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode* cur = head;
        while (cur->next) {
            if (cur->val == cur->next->val) {
                ListNode* temp = cur->next;
                cur->next = temp->next;
                delete(temp);
            } else cur = cur->next;
        }
        return head;
    }
};
// @lc code=end

