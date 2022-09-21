/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
class Solution {
public:
    // dfs 
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