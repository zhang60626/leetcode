/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 */

// @lc code=start
class Solution {
public:
    // time complexity: o(log(M+N)), M: rows of matrix, N: cols of matrix
    // space complexity: o(1)
    /*
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int row = 0;
        // search col
        for (int low = 0, high = matrix.size() - 1; low <= high;) {
            int mid = low + ((high - low) >> 1);
            if (matrix[mid][0] == target) {
                return true;
            } else if (matrix[mid][0] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
                row = mid;
            }
        }
        // search row
        for (int low = 0, high = matrix[row].size() - 1; low <= high;) {
            int mid = low + ((high - low) >> 1);
            if (matrix[row][mid] == target) {
                return true;
            } else if (matrix[row][mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return false;
    }
    */
    // Don't treat it as a matrix, treat it as a sorted array instead.
    // 1. treat it as a sorted array won't any improvement on time complexity
    // 2. m * n  may cause overflow when m and n are large
    // 3. / and & are expensive operation
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) {
            return false;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        int low = 0;
        int high = m * n - 1;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if(matrix[mid / n][mid % n] == target) {
                return true;
            } else if (matrix[mid / n][mid % n] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
    }
};
// @lc code=end

