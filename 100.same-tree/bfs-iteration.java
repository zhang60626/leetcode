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
class Solution {
    public boolean isSameTree(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (!check(p, q)) return false;
        
        Queue<TreeNode> queP = new LinkedList();
        Queue<TreeNode> queQ = new LinkedList();
        
        queP.add(p);
        queQ.add(q);
        while (!queP.isEmpty()) {
            p = queP.remove();
            q = queQ.remove();

            if (!check(p, q)) return false;
            if (p != null) {
                // Java not allow nulls be in Queue
                if (!check(p.left, q.left)) return false;
                if (p.left != null) {
                    queP.add(p.left);
                    queQ.add(q.left);
                }
                if (!check(p.right, q.right)) return false;
                if (p.right != null) {
                    queP.add(p.right);
                    queQ.add(q.right);
                }
            }
        }
        return true;
    }
    
    private boolean check(TreeNode p, TreeNode q) {
        if (p == null && q == null) return true;
        if (p == null || q == null) return false;
        if (p.val != q.val) return false;
        return true;
    }
    
}
