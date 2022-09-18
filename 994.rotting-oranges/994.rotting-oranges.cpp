/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:
    // see https://leetcode.com/problems/rotting-oranges/discuss/588024/C%2B%2B-or-BFS-or-100-Space-95-time-or-explanation-of-logic
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty()) return -1;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> dir = {0, -1, 0, 1, 0};
        int maxTime = -1;
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 2) q.push({i, j});
                else if (grid[i][j] == 1) ++fresh;
            }
        }
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                for (int i = 0; i < 4; ++i) {
                    int nr = q.front().first + dir[i];
                    int nc = q.front().second + dir[i + 1];
                    if (nr >= m || nr < 0 || nc < 0 || nc >= n 
                        || grid[nr][nc] == 0 || grid[nr][nc] == 2) {
                        continue;
                    }
                    --fresh;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
                q.pop();
            }
            maxTime++;
        }
        if (fresh) return -1;
        if (maxTime == -1) return 0; // no rotten oranges
        return maxTime;
    }
};
// @lc code=end

