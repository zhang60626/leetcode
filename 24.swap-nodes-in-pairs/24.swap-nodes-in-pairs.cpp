/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
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
    // time complexity: o(n), n is the length of linked list
    // space complexity: o(1)
    /*
    ListNode* swapPairs(ListNode* head) {
        ListNode* prev = head;
        ListNode** prevPair = &head;
        while (prev != nullptr && prev->next != nullptr) {
            ListNode* nextPair = prev->next->next;
            ListNode* p1 = prev;
            ListNode* p2 = prev->next;
            p2->next = p1;
            p1->next = nextPair;
            *prevPair = p2;
            prevPair = &p1->next;
            prev =  nextPair;
        }
        return head;
    }
    */
    // recursive version
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) 
            return head;
        
        ListNode* tmp = head;
        head = head->next;
        tmp->next = head->next;
        head->next = tmp;
        
        tmp->next = swapPairs(tmp->next);
        return head;
    }
};
// @lc code=end

