/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
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
    // two-pointers
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int len = 1;
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next) {
            fast = fast->next;
            len++;
        }
        if (k % len == 0) return head;
        k %= len;
        for (int i = len - k - 1; i > 0; --i) {
            slow = slow->next;
        }
        fast->next = head;
        head = slow->next;
        slow->next = nullptr;
        return head;
    }
};
// @lc code=end

