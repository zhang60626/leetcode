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
        List<List<Integer>> answer = new ArrayList();

        dfs(root, answer, 1);
        
        return answer;
    }
    
    private void dfs(Node root, List<List<Integer>> answer, int level) {
        if (root == null) return;
        
        if (level > answer.size()) {
            answer.add(new ArrayList());
        }
        
        answer.get(level - 1).add(root.val);
        
        for (Node node : root.children) {
            dfs(node, answer, level + 1);
        }
    }
}
