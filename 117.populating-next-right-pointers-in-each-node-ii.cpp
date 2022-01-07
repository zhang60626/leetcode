/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
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
    // use queue
    // time complexity: o(n), n: number of nodes in the tree
    // space complexity: o(n)
    Node* connect(Node* root) {
        if (!root) return nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                Node* cur = q.front();
                q.pop();
                if (size) cur->next = q.front();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }

    // o(1) space solution
    // time complexity: o(n), n: number of nodes in the tree
    // space complexity: o(1)
    Node* connect(Node* root) {
        if (!root) return nullptr;
        Node* head = root;
        Node nextLevel;
        Node* cur = &nextLevel;
        while (head) {
            while (head) {
                if (head->left) {
                    cur->next = head->left;
                    cur = cur->next;
                }
                if (head->right) {
                    cur->next = head->right;
                    cur = cur->next;
                }
                head = head->next;
            }
            head = nextLevel.next;
            nextLevel.next = nullptr;
            cur = &nextLevel;
        }
        return root;
    }

    // recursive
    Node* connect(Node* root) {
        dfs(root);
        return root;
    }

    void dfs(Node* root) {
        if (!root) return;
        if (root->left) root->left->next = root->right ? root->right : findNext(root->next);
        if (root->right) root->right->next = findNext(root->next);
        dfs(root->right);   /// dfs root->right first
        dfs(root->left);
    }
    
    Node* findNext(Node* root) {
        if (!root) return root;
        if (root->left) return root->left;
        if (root->right) return root->right;
        return findNext(root->next);
    }
};
// @lc code=end

