/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    // sort and merge
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for (int i = 0; i < intervals.size(); i++) {
            if (result.empty() || result.back()[1] < intervals[i][0]) {
                result.push_back(intervals[i]); 
            } else {
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            
            }
        }
        return result;
    }
};
// @lc code=end

