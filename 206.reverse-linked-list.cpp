/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        return dfs(head, nullptr);
    }

    ListNode* dfs(ListNode* head, ListNode* pre) {
        if (!head) return pre;
        ListNode* next = head->next;
        head->next = pre;
        return dfs(next, head);
    }
    // iterative
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* tail = head;
        ListNode* prev = nullptr;
        while (tail) {
            ListNode* next = tail->next;
            tail->next = prev;
            prev = tail;
            tail = next;
        }
        return prev;
    }
};
// @lc code=end

