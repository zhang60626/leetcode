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
    public boolean isPalindrome(ListNode head) {
        Deque<ListNode> deq = new ArrayDeque();
        
        while (head != null) {
            deq.addLast(head);
            head = head.next;
        }
        
        while (deq.size() > 1) {
            if (deq.removeFirst().val != deq.removeLast().val) {
                return false;
            }
        }
        
        return true;
    }
}
