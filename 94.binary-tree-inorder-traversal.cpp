/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        dfs(root, order);
        return order;
    }
    
    void dfs(TreeNode* root, vector<int>& order) {
        if (!root) return;
        dfs(root->left, order);
        order.push_back(root->val);
        dfs(root->right, order);
    }
    // iterative aaproach
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> order;
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top();
                s.pop();
                order.push_back(cur->val);
                cur = cur->right;
            }
        }
        return order;
    }
};
// @lc code=end

