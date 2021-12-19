/*
 * @lc app=leetcode id=350 lang=cpp
 *
 * [350] Intersection of Two Arrays II
 */

// @lc code=start
class Solution {
public:
    // sort array and compare
    // time complexity: o(n log(n))
    // space complexity: o(n)
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        for (int i = 0, j = 0; i < nums1.size() && j < nums2.size();) {
            if (nums1[i] == nums2[j]) {
                result.push_back(nums1[i]);
                ++i;
                ++j;
            } else if (nums1[i] < nums2[j]) {
                ++i;
            } else {
                ++j;
            }
        }
        return result;
    }
    // hash map approach
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> result;
        for (int i = 0; i < nums1.size(); ++i) {
            map[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i) {
            if (map[nums2[i]] > 0) {
                result.push_back(nums2[i]);
                map[nums2[i]]--;
            }
        }
        return result;
    }
};
// @lc code=end

