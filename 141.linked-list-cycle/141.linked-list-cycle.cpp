/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    // time complexity: o(n log(n))
    // space complexity: o(n)
    bool hasCycle(ListNode *head) {
        set<ListNode*> nodes;
        while (head) {
            // time complexity of find(): o(log n)
            if (nodes.find(head) != nodes.end()) {
                return true;
            }
            nodes.insert(head);
            head = head->next;
        }
        return false;
    }
    // slow and fast pointers
    // time complexity: o(n)
    // space complexity: o(1)
    bool hasCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next;
            if (slow == fast) return true;
            fast = fast->next;
            slow = slow->next;
        }
        return false;
    }
};
// @lc code=end

