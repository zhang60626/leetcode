/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        // copy list
        Node curr = head;
        while (curr != null) {
            Node t = new Node(curr.val);
            t.next = curr.next;
            curr.next = t;
            curr = t.next;
        }
        
        // copy random
        Node prev = head;
        while (prev != null) {
            curr = prev.next;
            if (prev.random != null) {
                curr.random = prev.random.next;
            }
            prev = curr.next;
        }
        
        // delete original node (expect head)
        curr = head;
        Node dummyHead = new Node(-1);
        Node p = dummyHead;
        while (curr != null) {
            p.next = curr.next;
            curr.next = curr.next.next;
            curr = curr.next;
            p = p.next;
        }
        
        return dummyHead.next;
    }
}