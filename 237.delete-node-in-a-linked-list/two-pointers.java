/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        ListNode curr = node.next;
        ListNode prev = node;
        
        while (curr.next != null) {
            swap(curr, prev);
            curr = curr.next;
            prev = prev.next;
        }
        swap(curr, prev);
        prev.next = null;
    }
    
    private void swap(ListNode a, ListNode b) {
        int t = a.val;
        a.val = b.val;
        b.val = t;
    }
}