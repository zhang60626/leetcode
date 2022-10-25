/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class BSTIterator {
    Queue<TreeNode> q = new LinkedList();
    TreeNode root;
    
    // space complexity: o(n). n: number of nodes in tree
    public BSTIterator(TreeNode root) {
        this.root = root;
        dfs(root);
    }
    
    public int next() {
        return q.remove().val;
    }
    
    public boolean hasNext() {
        return !q.isEmpty();
    }
    
    private void dfs(TreeNode root) {
        if (root == null) return;
        
        dfs(root.left);
        q.add(root);
        dfs(root.right);
    }
}

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator obj = new BSTIterator(root);
 * int param_1 = obj.next();
 * boolean param_2 = obj.hasNext();
 */
