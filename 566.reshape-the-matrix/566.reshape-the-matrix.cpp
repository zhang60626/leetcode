/*
 * @lc app=leetcode id=566 lang=cpp
 *
 * [566] Reshape the Matrix
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        if (mat.empty()) return mat;
        int m = mat.size();
        int n = mat[0].size();
        if (m * n != r * c) return mat;
        vector<vector<int>> newMat(r, vector<int>(c));
        for (int i = 0, a = 0, b = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                newMat[a][b++] = mat[i][j];
                if (b >= c) {
                    a++;
                    b = 0;
                }
            }
        }
        return newMat;
    }
};
// @lc code=end

