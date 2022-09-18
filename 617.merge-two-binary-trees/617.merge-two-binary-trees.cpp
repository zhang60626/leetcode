/*
 * @lc app=leetcode id=617 lang=cpp
 *
 * [617] Merge Two Binary Trees
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
    // recursive approach
    // time complexity: o(n), n: minimum number of nodes from two trees
    // space complexity: o(n), n: minimum number of nodes from two trees
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        return root1;
    }
    // iterative
    /*
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1) return root2;
        if (!root2) return root1;
        TreeNode* root = root1;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root1);
        s2.push(root2);
        while (!s1.empty()) {
            TreeNode* t1 = s1.top();
            TreeNode* t2 = s2.top();
            s1.pop();
            s2.pop();
            t1->val += t2->val;
            if (t1->left && t2->left) {
                s1.push(t1->left);
                s2.push(t2->left);
            } else if (!t1->left) {
                t1->left = t2->left;
            }
            if (t1->right && t2->right) {
                s1.push(t1->right);
                s2.push(t2->right);
            } else if (!t1->right) {
                t1->right = t2->right;
            }
        }
        return root;
    }
    */
};
// @lc code=end

