/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    // dfs
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j);
                    count++;
                }
            }
        }
        return count;
    }
    
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i, int j) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()) return;
        if (visited[i][j]) return; 
        visited[i][j] = 1;
        if (grid[i][j] == '1') {
            dfs(grid, visited, i - 1, j);
            dfs(grid, visited, i + 1, j);
            dfs(grid, visited, i, j - 1);
            dfs(grid, visited, i, j + 1);
        }
    }

    // BFS
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (visited[i][j] || grid[i][j] != '1') continue;
                q.push({i, j});
                count++;
                while (!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();
                    if (visited[r][c] || grid[r][c] != '1') continue;
                    visited[r][c] = 1;
                    if (r - 1 >= 0) q.push({r - 1, c});
                    if (r + 1 < grid.size()) q.push({r + 1, c});
                    if (c - 1 >= 0) q.push({r, c - 1});
                    if (c + 1 < grid[0].size()) q.push({r, c + 1});
                }
            }
        }
        return count;
    }
};

// union find
// time complexity: o(n), n: numbers of elements in matrix
// space complexity: o(n)
class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;
    int count;
public:
    UnionFind(vector<vector<char>>& grid) {
        count = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * grid[0].size() + j);
                    ++count;
                } else parent.push_back(-1);
                rank.push_back(0);
            }
        }
        
    }
    
    int find(int i) {
        if (parent[i] != i) {
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    
    void unite(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        if (rootx != rooty) { // 属于不同的树
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }
    
    int getCount() {
        return count;
    }
};

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        
        UnionFind uf(grid);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    grid[i][j] = '0';
                    if (i + 1 < m && grid[i + 1][j] == '1') uf.unite(i * n + j, (i + 1) * n + j);
                    if (j + 1 < n && grid[i][j + 1] == '1') uf.unite(i * n + j, i * n + j + 1);
                }
            }
        }
        return uf.getCount();
    }
};

// @lc code=end

