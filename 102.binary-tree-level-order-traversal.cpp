/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        if (!root) return order;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> temp;
            for (int i = q.size(); i > 0; i--) {
                TreeNode* tp = q.front();
                q.pop();
                temp.push_back(tp->val);
                if (tp->left) q.push(tp->left);
                if (tp->right) q.push(tp->right);
            }
            order.push_back(temp);
        }
        return order;
    }

    // DFS
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> order;
        dfs(root, order, 0);
        return order;
    }
    
    void dfs(TreeNode* root, vector<vector<int>>& order, int level) {
        if (!root) return;
        if (level == order.size()) order.push_back(vector<int>());
        order[level].push_back(root->val);
        dfs(root->left, order, level + 1);
        dfs(root->right, order, level + 1);
   
};
// @lc code=end

