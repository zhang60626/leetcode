/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode();
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode curr = head;
        int carry = 0;
        while (l1 != null && l2 != null) {
            ListNode t = new ListNode((l1.val + l2.val + carry) % 10);
            carry = (l1.val + l2.val + carry) / 10;
            curr.next = t;
            curr = curr.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null) {
            ListNode t = new ListNode((l1.val + carry) % 10);
            carry = (l1.val + carry) / 10;
            curr.next = t;
            curr = curr.next;
            l1 = l1.next;
        }
        while (l2 != null) {
            ListNode t = new ListNode((l2.val + carry) % 10);
            carry = (l2.val + carry) / 10;
            curr.next = t;
            curr = curr.next;
            l2 = l2.next;
        }
        if (carry > 0) {
            ListNode t = new ListNode(carry);
            curr.next = t;
        }
        
        return reverseList(head.next);
    }
    
    private ListNode reverseList(ListNode l) {
        ListNode ret = new ListNode();
        while (l != null) {
            ListNode t = l.next;
            l.next = ret.next;
            ret.next = l;
            l = t;
        }
        return ret.next;
    }
}
