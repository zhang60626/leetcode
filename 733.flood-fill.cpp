/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    // depth first search
    // time complexity: o(m * n)
    // space complexity: o(m * n), m: rows of matrix, n cols of matrix
    /*
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int originColor = image[sr][sc];
        vector<vector<int>> see(image.size(), vector<int>(image[0].size(), 0));
        for (int i = 0; i < image.size(); ++i) {
            for (int j = 0; j < image[0].size(); ++j) {
                if (image[i][j] != originColor) {
                    see[i][j] = 1;  // 不同原色的不需要遍历
                }
            }
        }
        dfs(image, see, sr, sc, newColor);
        return image;
    }
    void dfs(vector<vector<int>>& image, vector<vector<int>>& see, int i,
             int j, int newColor) {
        if (i < 0 || i >= image.size()) return;
        if (j < 0 || j >= image[0].size()) return;
        if (see[i][j]) return;
        image[i][j] = newColor;
        see[i][j] = 1;
        dfs(image, see, i - 1, j, newColor);
        dfs(image, see, i + 1, j, newColor);
        dfs(image, see, i, j - 1, newColor);
        dfs(image, see, i, j + 1, newColor);
    }
    */
    // breath first search
    // time complexity: o(m * n)
    // space complexity: o(m * n), m: rows of matrix, n cols of matrix
    /*
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
    */
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        dfs(image, sr, sc, image[sr][sc], newColor);
        return image;
    }    
    void dfs(vector<vector<int>>& image, int i, int j, int originColor, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()) return;
        if (image[i][j] != originColor) return;
        image[i][j] = newColor;
        dfs(image, i - 1, j, originColor, newColor);
        dfs(image, i + 1, j, originColor, newColor);
        dfs(image, i, j - 1, originColor, newColor);
        dfs(image, i, j + 1, originColor, newColor);
    }
};
// @lc code=end