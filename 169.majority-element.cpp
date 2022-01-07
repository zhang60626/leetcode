/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    // hashmap
    // time complexity: o(n)
    // space complexity: o(n)
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        for (int i = 0; i < nums.size(); ++i) {
            count[nums[i]]++;
        }
        int answear = 0;
        int maxCount = 0;
        for (pair<int, int> it : count) {
            if (it.second > maxCount) {
                maxCount = it.second;
                answear = it.first;
            }
        }
        return answear;
    }

    // sort
    // time complexity: o(n log(n))
    // space complexity: o(1) or o(n)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }

    // Boyer-Moore Voting Algorithm
    // see https://leetcode.com/problems/majority-element/solution/
    // approach 6
    // time complexity: o(n)
    // space complexity: o(1)
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) majority = nums[i];
            if (nums[i] == majority) ++count;
            else --count;
        }
        return majority;
    }

    // bit manipulation 
    // we assume that majority always exist
    int majorityElement(vector<int>& nums) {
        int len = sizeof(int) * 8;
        int hsize = nums.size() / 2;
        int result = 0;
        for (int i = 0; i < len; ++i) {
            int count = 0;
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[j] & (1 << i)) count++;
            }
            if (count > hsize) result += (1 << i);
        }
        return result;
    }

    // divide and conquer
    // time complexity: o(n log(n))
    // space complexity: o(log n)
    int majorityElement(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
    int helper(vector<int>& nums, int low, int high) {
        if (low == high) return nums[low];
        int mid = low + (high - low) / 2;
        int left = helper(nums, low, mid);
        int right = helper(nums, mid + 1, high);
        if (left == right) return left;
        int left_count = 0;
        int right_count = 0;
        for (int i = low; i < high + 1; ++i) {
            if (nums[i] == left) left_count++;
            else if (nums[i] == right) right_count++;
        }
        return left_count > right_count ? left : right;
    }
    
    // random
    // time complexity: worst o(inf) avg o(n)
    // space complexity: o(1)
    int majorityElement(vector<int>& nums) {
        int hsize = nums.size() / 2;
        while (true) {
            int majority = nums[rand() % nums.size()];
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (majority == nums[i]) count++;
            }
            if (count > hsize) return majority;
        }
        return -1;
    }
};
// @lc code=end

