/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // use std::set (std::unordered_set)
    // time complexity: o(n)
    // space complexity: o(n)
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> nodes;
        while (head) {
            if (nodes.find(head) != nodes.end()) {
                return head;
            }
            nodes.insert(head);
            head = head->next;
        }
        return nullptr;
    }
    // Floyd's cicle detection algorithm
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) break;
        }
        if (!fast || !fast->next) return nullptr;
        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
// @lc code=end

