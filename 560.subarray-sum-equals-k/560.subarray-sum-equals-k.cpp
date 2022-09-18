/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
class Solution {
public:
    // using cumulative sum (TLE)
    // time complexity: o(n^2)
    // space complexity: o(n)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        vector<int> prefix(nums.size() + 1, 0);
        for (int i = 1; i < prefix.size(); ++i) {
            prefix[i] = nums[i - 1] + prefix[i - 1];
        }
        for (int i = 1; i < prefix.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                if (prefix[i] - prefix[j] == k) count++;
            }
        }
        return count;
    }

    // using cumulative sum without extra space (TLE)
    // time complexity: o(n^2)
    // space complexity: o(1)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int sum = 0;
            for (int j = i; j < nums.size(); ++j) {
                sum += nums[j];
                if (sum == k) count++;
            }
        }
        return count;
    }

    // using hash map. see https://leetcode.com/problems/subarray-sum-equals-k/solution/
    // approach 4
    // time complexity: o(n)
    // space complexity: o(n)
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> hashmap;
        hashmap[0] = 1;
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            if (hashmap[sum - k]) count += hashmap[sum - k];
            hashmap[sum]++;
        }
        return count;
    }
};
// @lc code=end

