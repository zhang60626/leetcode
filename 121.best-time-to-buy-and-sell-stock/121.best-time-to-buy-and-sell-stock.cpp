/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    // brute force (time limit exceeded)
    // time complexity: o(n^2)
    // space complexity: o(1)
    /*
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (int i = 0; i < prices.size(); ++i) {
            for (int j = i + 1; j < prices.size(); ++j) {
                profit = max(profit, prices[j] - prices[i]);
            }
        }
        return profit;
    }
    */
    // two-pointers approach
    // time complexity: o(n)
    // space complexity: o(1)
    /*
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        for (int left = 0, right = 1; right < prices.size(); ++right) {
            profit = max(profit, prices[right] - prices[left]);
            if (prices[right] < prices[left]) {
                left = right;
            }
        }
        return profit;
    }
    */
    // dynamic programming approach
    // time complexity: o(n)
    // space complexity: o(1) 
    int maxProfit(vector<int>& prices) {
        if (prices.size() < 2) return 0;
        int profit = 0;
        int minPrice = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            profit = max(profit, prices[i] - minPrice);
            minPrice = min(prices[i], minPrice);
        }
        return profit;
    }
};
// @lc code=end

