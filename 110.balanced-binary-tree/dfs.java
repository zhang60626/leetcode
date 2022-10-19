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
    // o(n) approach. bottom-up solution
    public boolean isBalanced(TreeNode root) {
        return dfs(root) != -1;
    }
    
    public int dfs(TreeNode root) {
        if (root == null) return 0;
        
        int lh = dfs(root.left);
        int rh = dfs(root.right);
        if (lh == -1 || rh == -1 || Math.abs(lh - rh) > 1) { // not balanced
            return -1;
        }
        return Math.max(lh, rh) + 1;
    }
}
