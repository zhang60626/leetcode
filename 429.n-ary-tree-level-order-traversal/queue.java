/*
// Definition for a Node.
class Node {
    public int val;
    public List<Node> children;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, List<Node> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
    public List<List<Integer>> levelOrder(Node root) {
        if (root == null) return new ArrayList();
        
        List<List<Integer>> answer = new ArrayList();
        Queue<Node> q = new LinkedList();
        q.add(root);
        
        while (!q.isEmpty()) {
            List<Integer> curr = new ArrayList();
            int size = q.size();
            
            for (int i = 0; i < size; i++) {
                Node node = q.remove();
                curr.add(node.val);
                for (Node t : node.children) {
                    q.add(t);
                }
            }
            answer.add(curr);
        }
        
        return answer;
    }
}
