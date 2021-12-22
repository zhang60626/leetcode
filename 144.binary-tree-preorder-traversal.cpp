/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    // preorder traversal
    // depth first search
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        preorder(root, order);
        return order;
    }
    void preorder(TreeNode* root, vector<int>& order) {
        if (!root) return;
        order.push_back(root->val);
        preorder(root->left, order);
        preorder(root->right, order);
    }
    // iterative approach
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> order;
        if (!root) return order;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            order.push_back(cur->val);
            s.pop();
            if (cur->right) s.push(cur->right);
            if (cur->left) s.push(cur->left);
        }
        return order;
    }
};
// @lc code=end

