/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    // breath first search
    // time complexity: o(m * n)
    // space complexity: o(m * n), m: rows of matrix, n cols of matrix
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int m = image.size();
        int n = image[0].size();
        int originColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            if (image[i][j] == originColor) image[i][j] = newColor;
            else continue;
            if (i - 1 >= 0) q.push(make_pair(i - 1, j));
            if (i + 1 < m) q.push(make_pair(i + 1, j));
            if (j - 1 >= 0) q.push(make_pair(i, j - 1));
            if (j + 1 < n) q.push(make_pair(i, j + 1));
        }
        return image;
    }
};
// @lc code=end