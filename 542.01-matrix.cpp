/*
 * @lc app=leetcode id=542 lang=cpp
 *
 * [542] 01 Matrix
 */

// @lc code=start
class Solution {
public:
    // BFS
    // time complexity: o(m * n)
    // space complexity: o(m * n)
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return mat;
        int dir[] = {0, -1, 0, 1, 0};
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i< m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
            }
        }
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int nr = r + dir[i];
                int nc = c + dir[i + 1];ro
                if (nr >= m || nr < 0 || nc >=n || nc < 0 || mat[nr][nc] != -1) {
                    continue;
                }
                mat[nr][nc] = mat[r][c] + 1;
                q.push({nr, nc});
            }
        }
        return mat;
    }
    // DP
    // see https://leetcode.com/problems/01-matrix/discuss/1369741/C%2B%2BJavaPython-BFS-DP-solutions-with-Picture-Clean-and-Concise-O(1)-Space
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        const int MAX = m + n;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) continue;
                int top = MAX;
                int left = MAX;
                if (i - 1 >= 0) top = mat[i - 1][j];
                if (j - 1 >= 0) left = mat[i][j - 1];
                mat[i][j] = min(top, left) + 1;
            }
        }
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (mat[i][j] == 0) continue;
                int bottom = MAX;
                int right = MAX;
                if (i + 1 < m) bottom = mat[i + 1][j];
                if (j + 1 < n) right = mat[i][j + 1];
                mat[i][j] = min(mat[i][j], min(bottom, right) + 1);
            }
        }
        return mat;
    }
};
// @lc code=end

