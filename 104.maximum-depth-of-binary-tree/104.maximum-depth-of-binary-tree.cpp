/*
 * @lc app=leetcode id=104 lang=cpp
 *
 * [104] Maximum Depth of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // BFS
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        if (!root) return max_depth;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            for (int i = q.size(); i > 0; --i) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            max_depth++;
        }
        return max_depth;
    }
    // DFS
    int maxDepth(TreeNode* root) {
        int max_depth = 0;
        dfs(root, 1, max_depth);
        return max_depth;
    }
    
    void dfs(TreeNode* root, int cur_depth, int& max_depth) {
        if (!root) return;
        max_depth = max(max_depth, cur_depth);
        dfs(root->left, cur_depth + 1, max_depth);
        dfs(root->right, cur_depth + 1, max_depth);
    }
};
// @lc code=end

