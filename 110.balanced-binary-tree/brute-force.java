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
    public boolean isBalanced(TreeNode root) {
        if (root == null) return true;
        
        int lh = heightOfTree(root.left);
        int rh = heightOfTree(root.right);
        if (Math.abs(lh - rh) > 1) {
            return false;
        }
        return isBalanced(root.left) && isBalanced(root.right);
    }
    
    public int heightOfTree(TreeNode root) {
        if (root == null) return 0;
        
        int lh = heightOfTree(root.left);
        int rh = heightOfTree(root.right);
        return Math.max(lh, rh) + 1;
    }
}
