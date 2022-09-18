/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
 */

// @lc code=start
/*
// Definition for a Node.
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // iterative approach
    Node* connect(Node* root) {
        if (!root) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                Node* temp = q.front();
                q.pop();    
                if (i < n - 1) temp->next = q.front();
                else temp->next = nullptr;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
        }
        return root;
    }
    // recursive approach I
    Node* connect(Node* root) {
        if (!root) return root;
        helper(root, nullptr);
        return root;
    }
    void helper(Node* node, Node* bro) {
        if (!node) return;
        node->next = bro;
        helper(node->left, node->right);
        if (bro) {
            helper(node->right, bro->left);
            helper(bro->left, bro->right);
            helper(bro->right, nullptr);
        }
    }
    // recursive approach II
    Node* connect(Node* root) {
        if (root && root->left) {
            root->left->next = root->right;
            if (root->next) root->right->next = root->next->left;
            connect(root->left);
            connect(root->right);
        }
        return root;
    }
};
// @lc code=end

