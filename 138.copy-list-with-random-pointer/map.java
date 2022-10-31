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
        Map<Node, Integer> map = new HashMap();
        List<Node> list = new ArrayList();
        Node dummyHead = new Node(-1);
        
        Node scurr = head;
        Node dcurr = dummyHead;
        // copy list
        for (int i = 0; scurr != null; i++) {
            Node t = new Node(scurr.val);
            dcurr.next = t;
            dcurr = dcurr.next;
            map.put(scurr, i);
            list.add(dcurr);
            scurr = scurr.next;
        }
        
        dcurr = dummyHead.next;
        scurr = head;
        // copy random
        while (scurr != null) {
            if (scurr.random != null) {
                int index = map.get(scurr.random);
                dcurr.random = list.get(index);
            }
            scurr = scurr.next;
            dcurr = dcurr.next;
        }
        return dummyHead.next;
    }
}