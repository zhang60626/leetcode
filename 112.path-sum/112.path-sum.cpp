/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    // DFS
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right && targetSum == root->val) 
            return true;
        int num = targetSum - root->val;
        return hasPathSum(root->left, num) || hasPathSum(root->right, num);
    }
    // DFS iterative version
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> s;
        s.push({root, targetSum});
        while (!s.empty()) {
            TreeNode* cur = s.top().first;
            int sum = s.top().second;
            s.pop();
            if (!cur->left && !cur->right && cur->val == sum)
                return true;
            if (cur->left) s.push({cur->left, sum - cur->val});
            if (cur->right) s.push({cur->right, sum - cur->val});
        }
        return false;
    }
    // BFS
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* cur = q.front();
            q.pop();
            if (!cur->left && !cur->right && cur->val == targetSum)
                return true;
            if (cur->left) {
                cur->left->val += cur->val;
                q.push(cur->left);
            }
            if (cur->right) {
                cur->right->val += cur->val;
                q.push(cur->right);
            }
        }
        return false;
    }
};
// @lc code=end

