/*
 * @lc app=leetcode id=19 lang=cpp
 *
 * [19] Remove Nth Node From End of List
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;    // length of linked list
        ListNode prevHead(-1);  // add a head node.
        prevHead.next = head;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            len++;
        }
        ListNode *p1 = &prevHead;
        for (int i = 0; i < len - n; ++i) {
            p1 = p1->next;
        }
        ListNode *del = p1->next;
        p1->next = del->next;
        delete(del);
        return prevHead.next;
    }
    /*
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = head;
        while (n--) fast = fast->next;
        if (fast == nullptr) {
            ListNode *ret = head->next;
            delete(head);
            return ret; // remove first element
        }
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *del = slow->next;
        slow->next = del->next;
        delete(del);
        return head;
    }
    */
};
// @lc code=end

