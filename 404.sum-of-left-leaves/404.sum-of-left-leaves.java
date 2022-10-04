//Given the root of a binary tree, return the sum of all left leaves. 
//
// A leaf is a node with no children. A left leaf is a leaf that is the left 
//child of another node. 
//
// 
// Example 1: 
// 
// 
//Input: root = [3,9,20,null,null,15,7]
//Output: 24
//Explanation: There are two left leaves in the binary tree, with values 9 and 1
//5 respectively.
// 
//
// Example 2: 
//
// 
//Input: root = [1]
//Output: 0
// 
//
// 
// Constraints: 
//
// 
// The number of nodes in the tree is in the range [1, 1000]. 
// -1000 <= Node.val <= 1000 
// 
//
// Related Topics Tree Depth-First Search Breadth-First Search Binary Tree 👍 38
//90 👎 262


//leetcode submit region begin(Prohibit modification and deletion)

import java.util.ArrayDeque;
import java.util.Deque;

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
    public int sumOfLeftLeaves(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        q.addLast(root);
        int sum = 0;
        while (!q.isEmpty()) {
            TreeNode t = q.removeFirst();
            if (t == null) continue;
            if (t.left != null) {
                if (isLeaf(t.left)) sum += t.left.val;
                else q.addLast(t.left);
            }
            if (t.right != null && !isLeaf(t.right)) q.addLast(t.right);
        }
        return sum;
    }

    private boolean isLeaf(TreeNode root) {
        return root.left == null && root.right == null;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
