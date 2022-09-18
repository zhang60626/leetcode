/*
 * @lc app=leetcode id=240 lang=cpp
 *
 * [240] Search a 2D Matrix II
 */

// @lc code=start
class Solution {
public:
    // brute force (TLE)
    // time complexity: o(m * n)
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (target == matrix[i][j]) return true;
            }
        }
        return false;
    }

    // binary search for each row
    // time complexity: o(m log(n))
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix.size(); ++i) {
            int left = 0;
            int right = matrix[0].size() - 1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (matrix[i][mid] == target) return true;
                if (matrix[i][mid] > target) right = mid - 1;
                else if (matrix[i][mid] < target) left = mid + 1;
            }
        }
        return false;
    }

    // dfs
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return dfs(matrix, target, 0, matrix[0].size() - 1);
    }
    
    bool dfs(vector<vector<int>>& matrix, int target, int row, int col) {
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size())
            return false;
        if (matrix[row][col] == target) return true;
        if (matrix[row][col] > target) return dfs(matrix, target, row, col - 1);
        return dfs(matrix, target, row + 1, col);
    }

    // iterative
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0;
        int col = matrix[0].size() - 1;
        while (row < matrix.size() && col >= 0) {
            if (matrix[row][col] == target) return true;
            if (matrix[row][col] < target) row++;
            else col--;
        }
        return false;
    }
};
// @lc code=end

