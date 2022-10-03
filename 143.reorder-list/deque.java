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
    public void reorderList(ListNode head) {
        Deque<ListNode> nodes = new ArrayDeque();
        
        ListNode p = head.next;
        while (p != null) {
            nodes.add(p);
            p = p.next;
        }
        
        ListNode pre = head;
        while (nodes.size() > 0) {
            p = nodes.pollLast();
            if (p != null) {
                p.next = null;
                pre.next = p;
                pre = pre.next;
            }
            p = nodes.pollFirst();
            if (p != null) {
                p.next = null;
                pre.next = p;
                pre = pre.next;
            }
        }
        
    }
}
