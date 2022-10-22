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
        Deque<Integer> s1 = new ArrayDeque(); // stack
        Deque<Integer> s2 = new ArrayDeque(); // stack
        
        while (l1 != null) {
            s1.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            s2.push(l2.val);
            l2 = l2.next;
        }
        
        int carry = 0;
        while (!s1.isEmpty() && !s2.isEmpty()) {
            ListNode temp = head.next;
            head.next = new ListNode((s1.peek() + s2.peek() + carry) % 10, temp);
            carry = (s1.pop() + s2.pop() + carry) / 10;
        }
        while (!s1.isEmpty()) {
            ListNode temp = head.next;
            head.next = new ListNode((s1.peek() + carry) % 10, temp);
            carry = (s1.pop() + carry) / 10;
        }
        while (!s2.isEmpty()) {
            ListNode temp = head.next;
            head.next = new ListNode((s2.peek() + carry) % 10, temp);
            carry = (s2.pop() + carry) / 10;
        }
        if (carry > 0) {
            ListNode temp = head.next;
            head.next = new ListNode(carry, temp);
        }
         
        return head.next;
    }
    
}
