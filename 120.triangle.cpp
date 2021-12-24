/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    // from dowm to top
    // time complexity: o(n), n is numbers of elements in triangle
    // space complexity: o(1)
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (int j = triangle[i].size() - 1; j >= 0; --j) {
                triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1])
                                 + triangle[i][j];
            }
        }
        return triangle[0][0];
    }
};
// @lc code=end

