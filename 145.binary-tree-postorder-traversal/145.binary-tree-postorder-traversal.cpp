/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        dfs(root, order);
        return order;
    }
    
    void dfs(TreeNode* root, vector<int>& order) {
        if (!root) return;
        dfs(root->left, order);
        dfs(root->right, order);
        order.push_back(root->val);
    }
    // iterative approach
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> order;
        if (!root) return order;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* cur = s.top();
            s.pop();
            order.insert(order.begin(), cur->val);
            if (cur->left) s.push(cur->left);
            if (cur->right) s.push(cur->right);
        }
        return order;
    }
};
// @lc code=end

