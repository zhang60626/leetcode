/*
 * @lc app=leetcode id=876 lang=cpp
 *
 * [876] Middle of the Linked List
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
    // use a extra array to store each nodes
    // time complexity: o(n)
    // space complexity: o(n)
    /*
    ListNode* middleNode(ListNode* head) {
        vector<ListNode*> nodes;
        while (head) {
            nodes.push_back(head);
            head = head->next;
        }
        return nodes[nodes.size() / 2];
    }
    */
    // time complexity: o(n)
    // space complexity: o(1)
    /*
    ListNode* middleNode(ListNode* head) {
        int len = 0;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            len++;
        }
        int n = len / 2;
        while (n--) {
            head = head->next;
        }
        return head;
    }
    */
    // two-pointers
    // time complexity: o(n)
    // space complexity: o(1)
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next; 
        }
        return slow;
    }
};
// @lc code=end

