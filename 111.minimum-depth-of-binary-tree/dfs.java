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
    public int minDepth(TreeNode root) {
        return dfs(root, 0);
    }
    
    private int dfs(TreeNode root, int count) {
        if (root == null) return count;
        
        if (root.left == null) return 1 + dfs(root.right, 0);
        if (root.right == null) return 1 + dfs(root.left, 0);
        
        return 1 + Math.min(dfs(root.left, 0), dfs(root.right, 0));
    }
}