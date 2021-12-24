/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 */

// @lc code=start
class Solution {
public:
    // 回溯
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        if (n <=0 || k > n) return result;
        vector<int> temp;
        dfs(result, temp, n, k, 1);
        return result;
    }

    void dfs(vector<vector<int>>& result, vector<int>& temp, int n, int k, int level) {
        if (temp.size() == k) {
            result.push_back(temp);
            return;
        }
        if (temp.size() > k) return;
        for (int i = level; i <= n; ++i) {
            temp.push_back(i);
            dfs(result, temp, n, k, i + 1);
            temp.pop_back();
        }
    }
};
// @lc code=end

