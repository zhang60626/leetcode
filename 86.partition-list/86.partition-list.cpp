/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
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
    ListNode* partition(ListNode* head, int x) {
        ListNode leftHead(-1);  // dummy head
        ListNode rightHead(-1);  // dummy head
        ListNode* leftTail = &leftHead;
        ListNode* rightTail = &rightHead;
        while (head) {
            if (head->val < x) {
                leftTail->next = head;
                leftTail = leftTail->next;
            } else {
                rightTail->next = head;
                rightTail = rightTail->next;
            }
            head = head->next;
        }
        leftTail->next = rightHead.next;
        rightTail->next = nullptr;
        return leftHead.next;
    }
};
// @lc code=end

