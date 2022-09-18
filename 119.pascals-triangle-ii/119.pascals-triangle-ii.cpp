/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    // iterative
    // time complexity:
    // space complexity: o(n)
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 2) return vector<int>(rowIndex + 1, 1);
        vector<int> answear(rowIndex + 1, 0);
        answear[0] = answear[1] = 1;
        for (int i = 2; i <= rowIndex; i++) {
            int tmp = answear[0];
            for (int j = 1; j < i; ++j) {
                int t2 = answear[j];
                answear[j] = tmp + answear[j];
                tmp = t2;
            }
            answear[i] = 1;
        }
        return answear;
    }

    // recursive
    vector<int> getRow(int rowIndex) {
        if (rowIndex < 2) return vector<int>(rowIndex + 1, 1);
        vector<int> answear(rowIndex + 1, 1);
        vector<int> temp = getRow(rowIndex - 1);
        for (int i = 1; i < rowIndex; ++i) {
            answear[i] = temp[i - 1] + temp[i];
        }
        return answear;
    }

    // 使用二项式定理
    vector<int> getRow(int rowIndex) {
        vector<int> answear(rowIndex + 1, 0);
        long long int cal = 1;
        for (int i = 0; i <= rowIndex; ++i) {
            answear[i] = cal;
            cal = cal * (rowIndex - i) / (i + 1);
        }
        return answear;
    }
};
// @lc code=end

