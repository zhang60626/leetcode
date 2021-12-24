/*
 * @lc app=leetcode id=101 lang=cpp
 *
 * [101] Symmetric Tree
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
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            stack<int> s;
            for (int i = size; i > 0; --i) {
                TreeNode* t = q.front();
                q.pop();
                if (t->left) q.push(t->left);
                else {
                    if (t->val != INT_MIN) {
                        TreeNode* null_node = new TreeNode(INT_MIN, nullptr, nullptr);
                        q.push(null_node);
                    }
                }
                if (t->right) q.push(t->right);
                else {
                    if (t->val != INT_MIN) {
                        TreeNode* null_node = new TreeNode(INT_MIN, nullptr, nullptr);
                        q.push(null_node);
                    }
                }
                if (size == 1) continue;
                else if (i > size / 2) s.push(t->val);
                else {
                    if (t->val == s.top()) {
                        s.pop();
                    } else return false;
                }
            }
            if (!s.empty()) return false;
        }
        return true;
    }
};
// @lc code=end

