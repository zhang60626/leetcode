/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 */

// @lc code=start
class Solution {
public:
    // breath first search
    /*
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int maxArea = 0;
        int curArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j]) {
                    q.push({i, j});
                    while (!q.empty()) {
                        int r = q.front().first;
                        int c = q.front().second;
                        q.pop();                        
                        if (grid[r][c]) curArea++;
                        else continue;
                        if (r - 1 >= 0) q.push({r - 1, c});
                        if (r + 1 < m) q.push({r + 1, c});
                        if (c - 1 >= 0) q.push({r, c - 1});
                        if (c + 1 < n) q.push({r, c + 1});
                        grid[r][c] = 0; // 避免重复搜索
                    }
                    maxArea = max(maxArea, curArea);
                    curArea = 0;
                }
            }
        }
        return maxArea;
    }
    */
    // depth first search
    // time complexity: o(n), n: elements of grid
    // time complexity: o(n)
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, 0));
        int maxArea = 0;
        int curArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(grid, visited, curArea, i, j);
                maxArea = max(maxArea, curArea);
                curArea = 0;
            }
        }
        return maxArea;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int& curArea,
             int i, int j) {
        int m = grid.size();
        int n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) return;
        if (visited[i][j]) return;
        visited[i][j] = 1;
        if (grid[i][j]) {
            curArea++;
            dfs(grid, visited, curArea, i - 1, j);
            dfs(grid, visited, curArea, i + 1, j);
            dfs(grid, visited, curArea, i, j - 1);
            dfs(grid, visited, curArea, i, j + 1);
        }
    }
};
// @lc code=end

