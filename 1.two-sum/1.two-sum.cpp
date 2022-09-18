/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

// @lc code=start
class Solution {
public:
    
    // time: o(n^2) space: o(1)
    /*
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
    */

    // time: o(n)   space: o(n)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        unordered_map<int, int> hash_map;
        for (int i = 0; i < nums.size(); ++i) {
            int findnum = target - nums[i];
            
            if (hash_map.find(findnum) != hash_map.end()) {
                result.push_back(hash_map[findnum]);
                result.push_back(i);
                break;
            }
            hash_map.insert(make_pair(nums[i], i));
        }
        return result;
    }
};
// @lc code=end

