/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
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
    // my solution
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return head;
        ListNode dummyHead(INT_MIN, head);
        ListNode* prev = &dummyHead;
        ListNode* tail = head->next;
        while (tail) {
            int curVal = tail->val;
            if (prev->next->val == curVal) {
                while (prev->next && prev->next->val == curVal) {
                    ListNode* temp = prev->next;
                    prev->next = temp->next;
                    delete(temp);
                }
                tail = prev->next;
                if (!tail) break;
            } else {
                prev = prev->next;
            }
            tail = tail->next;
        }
        return dummyHead.next;        
    }
};
// @lc code=end

