/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
class Solution {
public:
    // DFS
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int count = 0;
        vector<vector<int>> visited(isConnected.size(), vector<int>(isConnected[0].size(), 0));
        for (int i = 0; i < isConnected.size(); ++i) {
            for (int j = 0; j < isConnected[0].size(); ++j) {
                if (visited[i][j]) continue;
                if (isConnected[i][j] == 1) {
                    count++;
                    dfs(isConnected, visited, i);
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<int>>& isConnected, vector<vector<int>>& visited, int row) {
        if (row < 0 || row >= isConnected.size()) return;
        for (int i = 0; i < isConnected[0].size(); ++i) {
            if (visited[row][i]) return;
            if (isConnected[row][i] == 1) {
                visited[row][i] = 1;
                dfs(isConnected, visited, i);    
            }
        }
    }
};

// union find
class UnionFind {
private:
    vector<int> parent;
    int count;
public:
    UnionFind(int size) {
        for (int i = 0; i < size; ++i) {
            parent.push_back(i);
        }
        count = size;
    }
    
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return;
        parent[rootx] = rooty;
        count--;
    }
    
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        if (isConnected.empty()) return 0;
        int n = isConnected.size();
        UnionFind uf(n);
        for (int i = 0; i < n; ++i) {
            int cur = -1;
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j] != 1) continue;
                if (cur == -1) cur = j;
                else uf.unite(j, cur);
            }
        }
        return uf.getCount();
    }
};
// @lc code=end

